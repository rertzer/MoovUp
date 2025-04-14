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

NAME 		= lamain

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

SRC_DIR		= src/

SRC			= Arm.cpp \
			  Finger.cpp \
			  Hand.cpp \
			  main.cpp

HEADER		= Arm.hpp \
			  Finger.hpp \
			  Hand.hpp \
			  Motor.hpp \
			  main.hpp

INCLUDE		=	-I./include

BIN			=	$(SRC:.cpp=.bin)

DEPS		= $(BIN:.bin=.d)

$(NAME):$(BIN)
	$(CXX) $(CFLAGS) $(INCLUDE) -mmcu=$(MMCU) $(DEBUG) $(BIN) -o $(NAME).bin
	avr-objcopy -j .text -j .data -g $(NAME).bin $(NAME).hex

%.bin: $(SRC_DIR)%.cpp
	@echo "rule $@"
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG) -mmcu=$(MMCU) -DF_CPU=$(F_CPU) -O1 -c  -MMD $< -o $@

all:
	@$(MAKE) --no-print-directory $(NAME)

flash:
	avrdude -c $(PROGRAMMER) -P $(PORT) -p $(PARTNO) -b $(B_RATE) -D "-Uflash:w:$(NAME).hex"

clean:
ifneq ("$(wildcard *.bin)", "")
	$(RM) -f *.bin
endif

ifneq ("$(wildcard *.hex)", "")
	$(RM) -f *.hex
endif

ifneq ("$(wildcard *.d)", "")
	$(RM) -f *.d
endif


re:	clean
	@$(MAKE) --no-print-directory

-include $(DEPS)

.PHONY: all clean flash re 
