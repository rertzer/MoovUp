/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Finger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:52:05 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/11 19:27:04 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Finger.hpp"

Finger::Finger(void)
{
}

Finger::Finger(Finger const &src)
{
	*this = src;	//	Copy everything manually
}

Finger	&Finger::operator=(Finger const &src)
{
	if (&src != this)
	{
		//	If something malloc'd, free current alloc, make new alloc, copy everyhing manually
	}
	return (*this);
}

Finger::~Finger(void)
{
}

int		Finger::getPressure(void) const
{
	return (this->_pressure);
}

void	Finger::setPressure(void)
{
	//	Hall sensor measurment
}

void	Finger::init(void) const
{
	//	Set finger to a start position
	//	Set motor PWM to something
}

void	Finger::move(unsigned int const pos) const
{
	//	Set finger's motor PWM to pos
	(void)pos;
}
