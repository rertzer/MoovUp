/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uart_printstrnl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:44:43 by fguarrac          #+#    #+#             */
/*   Updated: 2025/03/06 23:23:54 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uart_printstrnl.h"

void	uart_printstrnl(const char* str)
{
	while (str && *str)
		uart_tx(*(str++));
	uart_tx('\r');
	uart_tx('\n');
}
