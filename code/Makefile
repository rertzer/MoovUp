# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 22:19:34 by fguarrac          #+#    #+#              #
#    Updated: 2025/04/07 14:31:40 by fguarrac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	Hall

MAKE 		=	make
CXX			=	avr-g++
CXXFLAGS	=	-Wall -Wextra -Werror
MMCU		=	atmega2560
RM			=	$(shell which rm)

PORT		=	/dev/ttyUSB0
PARTNO		=	m2560
PROGRAMMER	=	wiring

F_CPU		=	16000000UL
B_RATE		=	115200

DEBUG		=

SRC			=	

HEADER		=	

INCLUDE		=	-I.

BIN			=	$(SRC:.c=.bin)

$(NAME): $(SRC)
	@$(MAKE) hex --no-print-directory
	@$(MAKE) flash --no-print-directory

%.bin: %.c $(HEADER)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG) -mmcu=$(MMCU) -DF_CPU=$(F_CPU) -O1 -c $< -o $@

all:
	@$(MAKE) --no-print-directory $(NAME)

hex: $(BIN)
	$(CC) $(CFLAGS) $(INCLUDE) -mmcu=$(MMCU) $(DEBUG) $(BIN) -o $(NAME).bin
	avr-objcopy -j .text -j .data -g $(NAME).bin $(NAME).hex

flash:
	avrdude -c $(PROGRAMMER) -P $(PORT) -p $(PARTNO) -b $(B_RATE) -D "-Uflash:w:$(NAME).hex"

clean:
ifneq ("$(wildcard *.bin)", "")
	$(RM) -f *.bin
endif

ifneq ("$(wildcard *.hex)", "")
	$(RM) -f *.hex
endif

re:	clean
	@$(MAKE) --no-print-directory
.PHONY: all clean flash hex re 
