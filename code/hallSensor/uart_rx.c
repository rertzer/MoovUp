/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uart_rx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:58:53 by fguarrac          #+#    #+#             */
/*   Updated: 2025/03/06 18:34:54 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uart_rx.h"

char	uart_rx(void)
{
	while (!(UCSR0A & (1 << RXC0)))	//	Wait for data to be received
		;
	return (UDR0);					//	Get and return received data from buffer
}
