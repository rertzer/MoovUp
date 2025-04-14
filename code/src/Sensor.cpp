/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sensor.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:26:34 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/14 16:31:47 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sensor.hpp"

Sensor::Sensor(void)
{
}

Sensor::Sensor(Sensor const &src)
{
	*this = src;	//	Copy everything manually
}

Sensor	&Sensor::operator=(Sensor const &src)
{
	if (&src != this)
	{
		//	If something malloc'd, free current alloc, make new alloc, copy everyhing manually
	}
	return (*this);
}

Sensor::~Sensor(void)
{
}

unsigned int	Sensor::getPressure(void) const
{
}

void			Sensor::setPressure(unsigned int)
{
}
