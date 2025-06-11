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

#/dev/ttyUSB0 ; tip: plug the device and enter sudo dmesg to get the port name
PORT		=	/dev/ttyACM0

PARTNO		=	m2560
PROGRAMMER	=	wiring

F_CPU		=	16000000UL
B_RATE		=	115200

DEBUG		=

SRC_DIR		= src/
BIN_DIR		= bin/
SUB_DIRS    = hallSensor/
BIN_PATHS = $(addprefix $(BIN_DIR), $(SUB_DIRS))

SRCPP			= main.cpp \
				Motor.cpp \
				MotorThumb.cpp \
				MotorIndex.cpp \
				MotorMiddle.cpp \
				MotorRing.cpp \
				MororPinky.cpp \
				MotorWrist.cpp \
				MotorElbow.cpp \
				MotorShoulder.cpp



SRC =		  hallSensor/uart_endl.c \
			  hallSensor/uart_init.c \
			  hallSensor/uart_printstr.c \
			  hallSensor/uart_printstrnl.c \
			  hallSensor/uart_rx.c \
			  hallSensor/uart_tx.c

HEADER		= main.hpp

INCLUDE		=	-I./include 

BIN			=	$(SRC:.c=.bin) $(SRCPP:.cpp=.bin)

BINS		= $(addprefix $(BIN_DIR), $(BIN)) 

DEPS		= $(BINS:.bin=.d)

all:
	@$(MAKE) --no-print-directory $(NAME)

$(NAME): $(BIN_DIR) $(BINS)
	$(CXX) $(CFLAGS) $(INCLUDE) -mmcu=$(MMCU) $(DEBUG) $(BINS) -o $(NAME).bin
	avr-objcopy -j .text -j .data -g $(NAME).bin $(NAME).hex
	#@$(MAKE) flash --no-print-directory

$(BIN_DIR):
	mkdir $(BIN_DIR)
	mkdir $(BIN_PATHS)


$(BIN_DIR)%.bin: $(SRC_DIR)%.c
	@echo "rule $@"
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG) -mmcu=$(MMCU) -DF_CPU=$(F_CPU) -O1 -c   $< -o $@

$(BIN_DIR)%.bin: $(SRC_DIR)%.cpp
	@echo "rule $@"
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG) -mmcu=$(MMCU) -DF_CPU=$(F_CPU) -O1 -c  -MMD $< -o $@

flash:
	@killall screen 2> /dev/null || true
	avrdude -c $(PROGRAMMER) -P $(PORT) -p $(PARTNO) -b $(B_RATE) -D "-Uflash:w:$(NAME).hex"
	@gnome-terminal -- screen $(PORT) $(B_RATE)

clean:
	rm -f $(BINS)
	rm -f $(DEPS)
	rm -f $(NAME).bin
	rm -fd $(BIN_PATHS)
	rm -fd $(BIN_DIR)

re:	clean
	@$(MAKE) --no-print-directory

-include $(DEPS)

.PHONY: all clean flash re 
