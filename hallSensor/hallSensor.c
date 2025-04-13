/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hallSensor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:21:12 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/02 18:51:25 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hallSensor.h"

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

		//	Set port
	DDRF &= ~(1u << DDF0);		//	Set pin A0 as input (Port F 0)
	PORTF &= ~(1u << PORTF0);	//	Disable pull up resistor

	uart_init();

		//	Init ADC
	ADMUX |= (1u << REFS0);		//	Set AVcc as reference
	ADCSRA |= (1u << ADEN);		//	Enable ADC
	ADCSRA |= (1u << ADPS0);	//	Set prescaler to 128
	ADCSRA |= (1u << ADPS1);	//	Set prescaler to 128
	ADCSRA |= (1u << ADPS2);	//	Set prescaler to 128

	DIDR0 |= (1u << ADC1D) | (1u << ADC2D) | (1u << ADC3D) | (1u << ADC4D) | (1u << ADC5D) | (1u << ADC6D) | (1u << ADC7D);							//	Disable unused ADC inputs
	DIDR1 |= (1u << ADC8D) | (1u << ADC9D) | (1u << ADC10D) | (1u << ADC11D) | (1u << ADC12D) | (1u << ADC13D) | (1u << ADC14D) | (1u << ADC14D);	//	Disable unused ADC inputs

	//	Dummy run for ADC initialisation
	ADCSRA |= (1u << ADSC);			//	Start conversion
	_delay_ms(10);					//	First conversion may take some time
	while (ADCSRA & (1u << ADSC));	//	Wait for ADC to finish conversion
	conv = ADC;						//	Read conversion

	//	Loop

	for (;;)
	{
		ADCSRA |= (1u << ADSC);			//	Start conversion
		while (ADCSRA & (1u << ADSC));	//	Wait for conversion to finish
		conv = ADC;
		ft_itoaptr(conv, digital);
		uart_printstrnl(digital);
		_delay_ms(20);
	}
}
