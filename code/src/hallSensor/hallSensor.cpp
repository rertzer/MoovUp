/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hallSensor.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:21:12 by fguarrac          #+#    #+#             */
/*   Updated: 2025/06/15 14:57:34 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hallSensor.hpp"

Hall::Hall(uint8_t pin): _pin(pin)
{
	this->_init();
}

Hall::Hall(Hall const &src): _pin(src.getPin())
{
}

Hall	&Hall::operator=(Hall const &src)
{
	if (this != &src)
		this->_pin = src.getPin();
	return (*this);
}

Hall::~Hall(void)
{
}

uint8_t		Hall::getPin(void) const
{
	return (this->_pin);
}

void		Hall::_init(void)
{
	//	Set port
	uint8_t bit = *g_pinToBit + this->_pin;
	uint8_t port = *g_pinToPort + this->_pin;

	uint8_t	*reg = (uint8_t *)(*g_portToMode + port);
	uint8_t	*out = (uint8_t *)(*g_portToOutput + port);

	uint8_t oldSREG = SREG;
    cli();
	*reg &= ~bit;
	*out &= ~bit;
	SREG = oldSREG;

	//	Init ADC
	ADMUX |= (1u << REFS0);	  //	Set AVcc as reference
	ADCSRA |= (1u << ADPS0);  //	Set prescaler to 128
	ADCSRA |= (1u << ADPS1);  //	Set prescaler to 128
	ADCSRA |= (1u << ADPS2);  //	Set prescaler to 128
	ADCSRA |= (1u << ADEN);	  //	Enable ADC

	//	Dummy run for ADC initialisation
	ADCSRA |= (1u << ADSC);	 //	Start conversion
	_delay_ms(10);			 //	First conversion may take some time
	while (ADCSRA & (1u << ADSC))
		;		 //	Wait for ADC to finish conversion
	(void)ADC;	 //	Read conversion
}

uint16_t	Hall::readValue(void)
{
	//	Wait for some conversion to finish (ADIF in ADCSRA) or check ADSC in ADCSRA?	///	Some other finger already may be reading the ADC
	while (!(ADCSRA & (1u << ADIF)))
		;							//	Wait for conversion to finish
//	while (ADCSRA & (1u << ADSC))
//		;  							//	Wait for conversion to finish
	//	Set ADC's input
	if (this->_pin > 7)				//	If ADC input > ADC7
		ADCSRB |= (1u << MUX5);		//	Set MUX5
	ADMUX &= 0xF8;					//	Clear previous ADC input
	ADMUX |= (this->_pin & 0x07);	//	Select new ADC input
	ADCSRA |= (1u << ADSC);	 		//	Start conversion
	while (ADCSRA & (1u << ADSC))
		;  							//	Wait for conversion to finish
	return (ADC);
}








static void ft_itoaptr(uint16_t conv, char* ptr) {
	uint16_t convTmp;
	uint8_t	 convLen;

	convLen = 1;
	convTmp = conv;
	while (convTmp /= 10)
		++convLen;
	ptr[convLen--] = '\0';
	if (conv == 0)
		ptr[convLen] = '0';
	while (conv > 0) {
		ptr[convLen--] = (conv % 10) + '0';
		conv /= 10;
	}
}

int main(void) {
	uint16_t	conv;
	char		digital[6];  //	Max value = 65535 + '\0'
	Uart		uart;
	Hall		hall(A0);

//	//	Init
//
//	//	Set port
//	DDRF &= ~(1u << DDF0);	   //	Set pin A0 as input (Port F 0)
//	PORTF &= ~(1u << PORTF0);  //	Disable pull up resistor
//
	uart.init();

	//	Init ADC
//	ADMUX |= (1u << REFS0);	  //	Set AVcc as reference
//	ADCSRA |= (1u << ADEN);	  //	Enable ADC
//	ADCSRA |= (1u << ADPS0);  //	Set prescaler to 128
//	ADCSRA |= (1u << ADPS1);  //	Set prescaler to 128
//	ADCSRA |= (1u << ADPS2);  //	Set prescaler to 128
//
//	DIDR0 |= (1u << ADC1D) | (1u << ADC2D) | (1u << ADC3D) | (1u << ADC4D) | (1u << ADC5D) | (1u << ADC6D) |
//			 (1u << ADC7D);	 //	Disable unused ADC inputs
//	DIDR1 |= (1u << ADC8D) | (1u << ADC9D) | (1u << ADC10D) | (1u << ADC11D) | (1u << ADC12D) | (1u << ADC13D) |
//			 (1u << ADC14D) | (1u << ADC14D);  //	Disable unused ADC inputs
//
//	//	Dummy run for ADC initialisation
//	ADCSRA |= (1u << ADSC);	 //	Start conversion
//	_delay_ms(10);			 //	First conversion may take some time
//	while (ADCSRA & (1u << ADSC))
//		;		 //	Wait for ADC to finish conversion
//	conv = ADC;	 //	Read conversion

	//	Loop

	for (;;) {
		//ADCSRA |= (1u << ADSC);	 //	Start conversion
		//while (ADCSRA & (1u << ADSC))
		//	;  //	Wait for conversion to finish
		//conv = ADC;
		conv = hall.readValue();
		ft_itoaptr(conv, digital);
		uart.printstrnl(digital);
		_delay_ms(20);
	}
}
