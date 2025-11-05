/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Uart.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:39:10 by fguarrac          #+#    #+#             */
/*   Updated: 2025/05/20 20:56:31 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Uart.hpp"
#include <string.h>
#include "ft_itoa.hpp"

Uart::Uart(void) : line_len(0) {}
Uart::Uart(Uart const& src) {
	*this = src;
}

Uart& Uart::operator=(Uart const& src) {
	if (this != &src) {
		strncpy(line, src.line, LINE_MAX_SIZE);
		line_len = src.line_len;
	}
	return (*this);
}

Uart::~Uart(void) {}

void Uart::init(void) {
	UBRR0 = 16;	 // F_CPU / (8 * BAUDO) - 1;
	UCSR0C |= (1u << UCSZ01);
	UCSR0C |= (1u << UCSZ00);
	UCSR0B |= (1u << TXEN0);
	UCSR0B |= (1u << RXEN0);
	UCSR0A |= (1 << U2X0);	// Double speed mode
							// UCSR0B |= (1u << RXCIE0);
}

void Uart::tx(char c) {
	while (!(UCSR0A & (1 << UDRE0)))
		;
	UDR0 = c;
}

char Uart::rx(void) {
	while (!(UCSR0A & (1 << RXC0)))
		;
	return (UDR0);
}

void Uart::printstrnl(char const* str) {
	while (str && *str)
		this->tx(*(str++));
	this->tx('\r');
	this->tx('\n');
}

void Uart::printstr(char const* str) {
	while (str && *str)
		this->tx(*(str++));
}

void Uart::printNbr(uint16_t nb) {
	char buffer[12];
	ft_itoa_dec(nb, buffer);
	printstr(buffer);
}

void Uart::endl(void) {
	this->tx('\r');
	this->tx('\n');
}

void Uart::readline() {
	line_len = 0;
	while (true) {
		uint8_t c = rx();
		tx(c);
		// printstr("read ");
		// printNbr((uint8_t)c);
		// endl();

		if (line_len < LINE_MAX_SIZE) {
			line[line_len] = c;
			++line_len;
		}
		if (c == '\r') {
			line[line_len - 1] = '\0';
			tx('\r');
			tx('\n');
			break;
		}
	}
}

char* Uart::getline() {
	return (line);
}

void Uart::printline() {
	for (uint8_t i = 0; i < line_len; ++i) {
		tx(line[i]);
	}
	tx('\r');
	tx('\n');
}

void Uart::resetline() {
	for (uint8_t i = 0; i < LINE_MAX_SIZE; ++i) {
		line[i] = '\0';
	}
	line_len = 0;
}
