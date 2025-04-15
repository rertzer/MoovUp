/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hallSensorUno.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:48:49 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/15 12:47:44 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hallSensor.hpp"

static void		ft_itoaptr(uint16_t conv, char *ptr)
{
	uint16_t	convTmp;
	uint8_t		convLen;

	convLen = 1;
	convTmp = conv;
	while (convTmp /= 10)
		++convLen;
	ptr[convLen--] = '\0';
	if (conv == 0)
		ptr[convLen] = '0';
	while (conv > 0)
	{
		ptr[convLen--] = (conv % 10) + '0';
		conv /= 10;
	}
}

int		main(void)
{
	uint16_t	conv;
	char		digital[6];	//	Max value = 65535 + '\0'

	//	Init

	uart_init();

	DDRC &= ~(1u << DDC0);		//	Set pin PC0 ass input
	PORTC &= ~(1u << PORTC0);	//	Disable pullup resistor

	ADMUX |= (1u << REFS0);		//	Select AVcc

	ADCSRA |= (1u << ADPS0);	//	Set prescaler to 128
	ADCSRA |= (1u << ADPS1);	//	Set prescaler to 128
	ADCSRA |= (1u << ADPS2);	//	Set prescaler to 128

	ADCSRA |= (1u << ADEN);		//	Enable ADC

	DIDR0 |= (1u << ADC5D) | (1u << ADC4D) | (1u << ADC3D) | (1u << ADC2D) | (1u << ADC1D);	//	Disable unused ADC inputs

	//	Dummy run for ADC initialization
	ADCSRA |= (1u << ADSC);	//	Start conversion
	_delay_ms(10);			//	First conversion may take some time
	while (ADCSRA & (1u << ADSC));
	conv = ADC;

	//	Loop

	for(;;)
	{
		ADCSRA |= (1u << ADSC);			//	Start conversion
		while (ADCSRA & (1u << ADSC));	//	Wait for conversion to finish
		conv = ADC;
		ft_itoaptr(conv, digital);
		uart_printstrnl(digital);
		_delay_ms(20);
	}
}
