/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Uart.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:29:08 by fguarrac          #+#    #+#             */
/*   Updated: 2025/05/20 20:56:52 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UART_HPP
#define UART_HPP

#include <avr/io.h>

class Uart {
   public:
	Uart(void);
	Uart(Uart const&);
	Uart& operator=(Uart const&);
	~Uart(void);

	void init(void);
	void tx(char);
	char rx(void);
	void printstrnl(char const*);
	void printstr(char const*);
	void printNbr(uint16_t nb);
	void endl(void);
};

#endif
