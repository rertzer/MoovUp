/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uart_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:37:57 by fguarrac          #+#    #+#             */
/*   Updated: 2025/03/06 18:38:47 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uart_init.h"

void	uart_init(void)
{
	//	B_RATE = 115200
	//	UBRRn(L) = (F.osc / (16 * B_RATE)) - 1	//	Asynchronous normal mode
	//	Frame format : 1 start bit, 8 data bits, no parity bit, 1 stop bit
	//	The USART has to be initialized before any communication can take place. The initialization process normally consists of setting the baud rate, setting frame format and enabling the Transmitter or the Receiver depending on the usage. For interrupt driven USART operation, the Global Interrupt Flag should be cleared (and interrupts globally disabled) when doing the initialization.

	//	UCSZn2 combined with the UCSZn1:0 bit in UCSRnC	8 bits => UCSZn2=0, UCSZn1=1, UCSZn0=1	//	Set char size
	//	UCSRnC		//	Seems fine with default values for 8N1...	0b00000110
	//	UBRRnH		//	Contains the four most significant bits of the USART baud rate
	//	UBRRNL		//	Contains the eight least significant bits of the USART baud rate

	UBRR0 = 8;					//	UBRRN = (F_CPU / (16 * B_RATE)) - 1
	UCSR0C |= (1u << UCSZ01);	//	Set char size to 8 bits
	UCSR0C |= (1u << UCSZ00);	//	Set char size to 8 bits
	UCSR0B |= (1u << TXEN0);	//	Enable USART transmitter
	UCSR0B |= (1u << RXEN0);	//	Enable USART reception
}
