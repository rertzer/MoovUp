/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Motor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:45:32 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/14 16:23:02 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Motor.hpp"

Motor::Motor(void)
{
}

Motor::Motor(Motor const &src)
{
	*this = src;	//	Copy everything manually
}

Motor	&Motor::operator=(Motor const &src)
{
	if (&src != this)
	{
		//	If something malloc'd, free current alloc, make new alloc, copy everyhing manually
	}
	return (*this);
}

Motor::~Motor(void)
{
}

void			Motor::_setPosition(unsigned int pos)
{
	this->_position = pos;	//	Some checks needed ?
}

unsigned int	Motor::getPosition(void) const
{
	return (this->_position);
}

void			Motor::smoothMove(unsigned int)
{
}

void			Motor::smartMove(unsigned int)
{
}

void			Motor::fastMove(unsigned int)
{
}
