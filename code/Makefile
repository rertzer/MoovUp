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
SUB_DIRS    = sensors/, motors/, arm/, uart/
BIN_PATHS = $(addprefix $(BIN_DIR), $(SUB_DIRS))

SRCPP			= main.cpp \
				motors/Motor.cpp \
				motors/MotorThumb.cpp \
				motors/MotorIndex.cpp \
				motors/MotorMiddle.cpp \
				motors/MotorRing.cpp \
				motors/MotorPinky.cpp \
				motors/MotorWrist.cpp \
				motors/MotorElbow.cpp \
				motors/MotorShoulder.cpp \
				arm/Finger.cpp \
				arm/Thumb.cpp \
				arm/Index.cpp \
				arm/Middle.cpp \
				arm/Ring.cpp \
				arm/Pinky.cpp \
				arm/Elbow.cpp \
				arm/Shoulder.cpp \
				arm/Wrist.cpp \
				sensors/hallSensor.cpp \
				uart/Uart.cpp


HEADER		= main.hpp

INCLUDE		=	-I./include 

BIN			=$(SRCPP:.cpp=.bin)

BINS		= $(addprefix $(BIN_DIR), $(BIN)) 

DEPS		= $(BINS:.bin=.d)

all:
	@$(MAKE) --no-print-directory $(NAME)

$(NAME):  $(BINS)
	$(CXX) $(CFLAGS) $(INCLUDE) -mmcu=$(MMCU) $(DEBUG) $(BINS) -o $(NAME).bin
	avr-objcopy -j .text -j .data -g $(NAME).bin $(NAME).hex
	@$(MAKE) flash --no-print-directory

$(BIN_DIR):
	@echo "toto"
	mkdir -p $(BIN_DIR)
	mkdir -p $(BIN_PATHS)


$(BIN_DIR)%.bin: $(SRC_DIR)%.cpp
	@echo "rule $@"
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG) -mmcu=$(MMCU) -DF_CPU=$(F_CPU) -O1 -c  -MMD -MP $< -o $@

flash:
	@killall screen 2> /dev/null || true
	avrdude -c $(PROGRAMMER) -P $(PORT) -p $(PARTNO) -b $(B_RATE) -D "-Uflash:w:$(NAME).hex"
	gnome-terminal -- screen $(PORT)  $(B_RATE)

clean:
	rm -rfd $(BINS)
	rm -rfd $(DEPS)
	rm -rfd $(NAME).bin
	rm -rfd $(BIN_PATHS)
	rm -rfd $(BIN_DIR)

re:	clean
	@$(MAKE) --no-print-directory

-include $(DEPS)

.PHONY: all clean flash re 
