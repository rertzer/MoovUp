/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uart_printstrnl.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:44:43 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/15 12:53:59 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uart_printstrnl.hpp"

void	uart_printstrnl(const char* str)
{
	while (str && *str)
		uart_tx(*(str++));
	uart_tx('\r');
	uart_tx('\n');
}
