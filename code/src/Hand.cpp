/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hand.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:58:57 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/11 19:30:23 by fguarrac         ###   ########.fr       */
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

Finger	Hand::getFinger(int finger) const
{
	return (this->_fingers[finger]);
}

void	Hand::init(void) const
{
	//	Set wrist position PWM
	//	Set fingers PWM
	//	Init fingers
	for (int i = 0; i < 5; i++)
		getFinger(i).init();
}

void	Hand::close(void) const
{
	//	Set finger PWM in sequence, until every finger's pressure is at target pressure.

	//	this->_finger[E_THUMB].moveFinger = THUMBCLOSED;	//	Set PWM value.	//	Use defines for THUMBCLOSED?
	//	this->_finger[E_INDEX].moveFinger = INDEXCLOSED;	//	Set PWM value.	//	...
	//	...
}

void	Hand::open(void) const
{
	//	Wait for pressure variation to reach target value, then set PWM in sequence to release glass

	//	this->_finger[E_PINKY].moveFinger = PINKYOPEN;	//	Set PWM value.	//	Use defines for THUMBCLOSED?
	//	this->_finger[E_RING].moveFinger = RINGOPEN;	//	Set PWM value.	//	...
	//	...
}
