/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uart_printstr.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:44:43 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/15 12:52:42 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uart_printstr.hpp"

void	uart_printstr(const char* str)
{
	while (str && *str)
		uart_tx(*(str++));
}
