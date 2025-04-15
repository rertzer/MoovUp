/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hand.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:58:57 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/15 16:51:55 by fguarrac         ###   ########.fr       */
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

enum e_state	Hand::getState(void) const
{
	return (this->_state);
}

Motor	Hand::getMotor(unsigned int nbr)
{
	return (this->_motor[nbr]);
}

void	Hand::init(void) const
{
	//	Set arm to start position
	//	Set wrist to start position
	//	Set fingers to start position
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
			if ((this->_sensor[INDEX].getPressure() > P1 || this->_sensor[MIDDLE].getPressure() > P1)
					&& this->_sensor[THUMB].getPressure() < P2)	//	Thumb sensor not at P2 really needed ? To avoid closing hand if object already touches thum ?
				this->_state = E_CLOSE;
			break ;
		}
		case E_CLOSE:
		{
			//	Make little hand movement to acknowledge glass is in hand ?
			//	Close hand
			//	while (thumb pressure < treshold value)
				//	Close thumb
			this->_motor[THUMB].smoothMove(THUMB_CLOSED_POS, P3);
			//	Then close ring and pinky until pressure changes for those fingers (Or define some pressures to keep it simple)
			this->_motor[RING].smoothMove(RING_CLOSED_POS, P4);
			this->_motor[PINKY].smoothMove(PINKY_CLOSED_POS, P5);
			this->_state = E_WAIT_BEFORE_SERVE;
			break ;
		}
		case E_WAIT_BEFORE_SERVE:
		{
			//	Delay
			//	Make little hand movement to annonce movement will start ?	(wrist movement)
			this->_state = E_MOVE_TO_SERVE;
			break ;
		}
		case E_MOVE_TO_SERVE:
		{
			this->_motor[ARM].smartMmove(ARM_SERV_POS);	//	Make it smooth ! (Using new smartMove function)
			this->_state = E_SERV;
			break ;
		}
		case E_SERV:
		{
			//	Wait for glass to be touched by human (pressure change in some fingers)
				//	if (some_finger's_pressure > release pressure)
					//	this->_state = E_OPEN;
			break ;
		}
		case E_OPEN:
		{
			//	Start opening hand by pinky finger
			//	Then ring finger
			//	...
			this->_motor[PINKY].smoothMove(PINKY_OPEN_POS);
			this->_motor[RING].smoothMove(RING_OPEN_POS);
			this->_motor[MIDDLE].smoothMove(MIDDLE_OPEN_POS);
			//	Maybe keep thumb not fully open to still hold glass ?
			this->_state = E_WAIT_BEFORE_GRAB;
			break ;
		}
		case E_WAIT_BEFORE_GRAB:
		{
			//	Delay
			//	Make little hand movement to annonce movement will start ?	(wrist movement)
			//	Fully open thumb ?
			this->_state = E_MOVE_TO_GRAB;
			break ;
		}
		case E_MOVE_TO_GRAB:
		{
			this->_motor[ARM].smartMove(ARM_GRAB_POS);	//	Make it smooth ! (Using new smartMove function)
			this->_state = E_GRAB;
			break ;
		}
	}
}
