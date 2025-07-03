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

Uart::Uart(void) {}

static char*	chop_nbr_dec(char* buffer, uint16_t nb, uint16_t len);
static uint16_t ft_getlen_dec(uint16_t nb);
void			ft_itoa_dec(uint16_t nb, char* buffer);

Uart::Uart(Uart const& src) {
	*this = src;
}

Uart& Uart::operator=(Uart const& src) {
	if (this != &src)
		*this = src;
	return (*this);
}

Uart::~Uart(void) {}

void Uart::init(void) {
	UBRR0 = 8;
	UCSR0C |= (1u << UCSZ01);
	UCSR0C |= (1u << UCSZ00);
	UCSR0B |= (1u << TXEN0);
	UCSR0B |= (1u << RXEN0);
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

static char* chop_nbr_dec(char* buffer, uint16_t nb, uint16_t len) {
	char base[17] = "0123456789";
	while (nb / 10) {
		--len;
		buffer[len] = base[nb % 10];
		nb = nb / 10;
	}
	buffer[len - 1] = base[nb % 10];
	return (buffer);
}

static uint16_t ft_getlen_dec(uint16_t nb) {
	uint16_t len;

	len = 1;
	while (nb / 10) {
		nb = nb / 10;
		++len;
	}
	return (len);
}

void ft_itoa_dec(uint16_t nb, char* buffer) {
	uint16_t len;

	len = ft_getlen_dec(nb);
	buffer[len] = '\0';
	(chop_nbr_dec(buffer, nb, len));
}
