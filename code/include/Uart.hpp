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

#define LINE_MAX_SIZE (uint8_t)80
#define F_CPU 16000000UL
#define BAUDO 9600UL

class Uart {
   public:
	Uart(void);
	Uart(Uart const&);
	Uart& operator=(Uart const&);
	~Uart(void);

	void  init(void);
	void  tx(char);
	char  rx(void);
	void  printstrnl(char const*);
	void  printstr(char const*);
	void  printNbr(uint16_t nb);
	void  endl(void);
	void  readline();
	void  printline();
	char* getline();
	void  resetline();

   private:
	char	line[LINE_MAX_SIZE];
	uint8_t line_len;
};

#endif
