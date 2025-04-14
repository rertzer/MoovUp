/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hand.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:58:57 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/14 14:57:30 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hand.hpp"

Hand::Hand(void)
{
}

Hand::Hand(Hand const &src)
{
	*this = src;	//	Copy everything manually
}

Hand	&Hand::operator=(Hand const &src)
{
	if (&src != this)
	{
		//	If something malloc'd, free current alloc, make new alloc, copy everyhing manually
	}
	return (*this);
}

Hand::~Hand(void)
{
}

void	Hand::init(void) const
{
	//	Set wrist position PWM
	//	Set fingers PWM
}

void	Hand::close(void) const
{
}

void	Hand::open(void) const
{
}
