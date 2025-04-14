/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hand.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:58:57 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/14 19:18:59 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hand.hpp"

Hand::Hand(void) : _state(E_GRAB)
{
}

Hand::Hand(Hand const &src)
{
	this->_state = src.getState();
	//	copy motors
	//	copy sensors	//	Usefull to copy pressures since they will be updated continuously ?
}

Hand	&Hand::operator=(Hand const &src)
{
	if (&src != this)
	{
		//	If something malloc'd, free current alloc, make new alloc, copy everyhing manually

		this->_state = src.getState();
		//	copy motors
		//	copy sensors	//	Usefull to copy pressures since they will be updated continuously ?
	}
	return (*this);
}

Hand::~Hand(void)
{
}

Hand::getState(void) const
{
	return (this->_state);
}

Motor	Hand::getMotor(unsigned int nbr)
{
	return (this->_motor[nbr]);
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

void	Hand::update(void)
{
	switch (this->_state)
	{
		case E_GRAB:
		{
			//	Wait for target pressure to be reached
				//	if (some_finger's_pressure > grab pressure)
					//	this->_state = E_CLOSE;
			break ;
		}
		case E_CLOSE:
		{
			//	Make little hand movement to acknowledge glass is in hand ?
			//	Close hand
			//	while (thumb pressure < treshold value)
				//	close thumb, index and middle finger
			//	this->_state = E_WAIT_BEFORE_SERVE;
			break ;
		}
		case E_WAIT_BEFORE_SERVE:
		{
			//	Delay
			//	Make little hand movement to annonce movement will start ?
			//	this->_state = E_MOVE_TO_SERVE;
			break ;
		}
		case E_MOVE_TO_SERVE:
		{
			//	hand.getMotor(x).smartMmove(ARM_SERV_POS);	//	Make it smooth ! (Using new smartMove function)
			//	this->_state = E_SERV;
			break ;
		}
		case E_SERV:
		{
			//	Wait for target pressure to be read
				//	if (some_finger's_pressure > release pressure)
					//	this->_state = E_OPEN;
			break ;
		}
		case E_OPEN:
		{
			//	Start opening hand by pinky finger
			//	Then ring finger
			//	...
			//	Maybe keep thumb not fully open to still hold glass ?
			//	this->_state = E_WAIT_BEFORE_GRAB;
			break ;
		}
		case E_WAIT_BEFORE_GRAB:
		{
			//	Delay
			//	Make little hand movement to annonce movement will start ?
			//	Fully open thumb ?
			//	this->_state = E_MOVE_TO_GRAB;
			break ;
		}
		case E_MOVE_TO_GRAB:
		{
			//	hand.getMotor(x).smartMove(ARM_GRAB_POS);	//	Make it smooth ! (Using new smartMove function)
			//	this->_state = E_GRAB;
			break ;
		}
	}
}
