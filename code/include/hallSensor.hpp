/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hallSensor.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:46:40 by fguarrac          #+#    #+#             */
/*   Updated: 2025/06/15 01:12:57 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HALLSENSOR_HPP
#define HALLSENSOR_HPP

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define _BV(bit) (1 << (bit))

#define PA 1
#define PB 2
#define PC 3
#define PD 4
#define PE 5
#define PF 6
#define PG 7
#define PH 8
#define PJ 10
#define PK 11
#define PL 12

#define A0 54
#define A1 55
#define A2 56
#define A3 57
#define A4 58
#define A5 59
#define A6 60
#define A7 61
#define A8 62
#define A9 63
#define A10 64
#define A11 65
#define A12 66
#define A13 67
#define A14 68
#define A15 69

#define NOT_A_PORT 0

extern uint8_t	g_pinToPort[];
extern uint8_t	g_pinToBit[];
extern uint16_t g_portToBit[];
extern uint16_t g_portToOutput[];

class Hall {
	uint8_t _pin;

	void _init(void);

   public:
	Hall(uint8_t);
	Hall(Hall const&);
	Hall& operator=(Hall const&);
	~Hall(void);

	uint8_t	 getPin(void) const;
	uint16_t readValue(void) const;
};

#endif
