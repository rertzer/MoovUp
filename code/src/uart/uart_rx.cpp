/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uart_rx.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:58:53 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/15 12:55:14 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uart_rx.hpp"

char	uart_rx(void)
{
	while (!(UCSR0A & (1 << RXC0)))	//	Wait for data to be received
		;
	return (UDR0);					//	Get and return received data from buffer
}
