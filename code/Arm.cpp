/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arm.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:06:16 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/11 19:29:43 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Arm.hpp"

Arm::Arm(void)
{
}

Arm::Arm(Arm const &src)
{
	*this = src;	//	Copy everything manually
}

Arm		&Arm::operator=(Arm const &src)
{
	if (&src != this)
	{
		//	If something malloc'd, free current alloc, make new alloc, copy everyhing manually
	}
	return (*this);
}

Arm::~Arm(void)
{
}

Hand	Arm::getHand(void) const
{
	return (this->_hand);
}

void	Arm::init(void) const
{
	//	Set arm to a start position
	//	Set motor PWM to something
	//	Init hand
	getHand().init();
}

void	Arm::move(unsigned int const pos) const
{
	//	Set motor PWM to pos
	(void)pos;
}
