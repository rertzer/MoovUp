/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uart_tx.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:39:31 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/15 12:56:12 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uart_tx.hpp"

void	uart_tx(char c)
{
	while (!(UCSR0A & (1 << UDRE0)))	//	Wait for empty transmit buffer
		;
	UDR0 = c;							//	Put data into buffer, sends the data
}
