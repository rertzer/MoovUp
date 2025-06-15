/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sensor.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:26:34 by fguarrac          #+#    #+#             */
/*   Updated: 2025/06/15 15:22:07 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sensor.hpp"

Sensor::Sensor(uint8_t pin): _pin(pin)
{
	this->_init();
}

Sensor::Sensor(Sensor const &src): _pin(src.getPin())	//	Copy everything else
{
}

Sensor	&Sensor::operator=(Sensor const &src)
{
	if (&src != this)
		this->_pin = src.getPin();
	return (*this);
}

Sensor::~Sensor(void)
{
}

//unsigned int	Sensor::getPressure(void) const volatile
//{
//	return (this->_pressure);
//}
//
//void			Sensor::setPressure(unsigned int pressure)
//{
//	this->_pressure = pressure;
//}

uint8_t		Sensor::getPin(void) const
{
	return (this->_pin);
}

void		Sensor::_init(void)
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

uint16_t	Sensor::readPressure(void)
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
