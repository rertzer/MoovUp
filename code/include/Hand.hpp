/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hand.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:58:57 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/15 13:22:03 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAND_HPP
# define HAND_HPP

# include "Motor.hpp"
# include "Sensor.hpp"

enum e_state
{
	E_GRAB,
	E_CLOSE,
	E_WAIT_BEFORE_SERVE,
	E_MOVE_TO_SERVE,
	E_SERV,
	E_OPEN,
	E_WAIT_BEFORE_GRAB,
	E_MOVE_TO_GRAB
};

class	Hand
{
	Motor			_motor[7];
	volatile Sensor	_sensor[5];
	enum e_state	_state;

public:

	Hand(void);
	Hand(Hand const &);
	Hand	&operator=(Hand const &);
	~Hand(void);

	enum e_state	getState(void) const;
	Motor			getMotor(unsigned int);

	void	init(void) const;
	void	close(void) const;
	void	open(void) const;
	void	update(void);
	//	Animate hand
	//	Rock, paper, scissors
	//	..
};

#endif
