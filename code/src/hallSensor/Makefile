# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 22:19:34 by fguarrac          #+#    #+#              #
#    Updated: 2025/06/03 17:13:38 by fguarrac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	Hall

MAKE 		=	make
CXX			=	avr-g++
CXXFLAGS	=	-Wall -Wextra -Werror
MMCU		=	atmega328p	#atmega2560
RM			=	$(shell which rm)

PORT		=	/dev/ttyUSB0
PARTNO		=	m328p		#m2560
PROGRAMMER	=	arduino		#wiring

F_CPU		=	16000000UL
B_RATE		=	115200

DEBUG		=

SRC			=	hallSensor.cpp		uart/Uart.cpp

HEADER		=	hallSensor.hpp		uart/Uart.hpp

INCLUDE		=	-I. -I./uart

BIN			=	$(SRC:.c=.bin)

$(NAME): $(SRC)
	@$(MAKE) hex --no-print-directory
	@$(MAKE) flash --no-print-directory

%.bin: %.c $(HEADER)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG) -mmcu=$(MMCU) -DF_CPU=$(F_CPU) -O1 -c $< -o $@

.PHONY: all
all:
	@$(MAKE) --no-print-directory $(NAME)

.PHONY: hex
hex: $(BIN)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -mmcu=$(MMCU) $(DEBUG) $(BIN) -DF_CPU=$(F_CPU) -o $(NAME).bin
	avr-objcopy -j .text -j .data -g $(NAME).bin $(NAME).hex

.PHONY: flash
flash:
	avrdude -c $(PROGRAMMER) -P $(PORT) -p $(PARTNO) -b $(B_RATE) -D "-Uflash:w:$(NAME).hex"

.PHONY: clean
clean:
ifneq ("$(wildcard *.bin)", "")
	$(RM) -f *.bin
endif

ifneq ("$(wildcard *.hex)", "")
	$(RM) -f *.hex
endif

.PHONY: re
re:	clean
	@$(MAKE) --no-print-directory
