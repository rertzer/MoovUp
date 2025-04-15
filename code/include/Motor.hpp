/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Motor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:58:53 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/15 13:22:25 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOTOR_HPP
# define MOTOR_HPP

# define ARM_SERV_POS
# define ARM_GRAB_POS

enum	e_finger
{
	E_THUMB,
	E_INDEX,
	E_MIDDLE,
	E_RING,
	E_PINKY
};

class Motor
{
	unsigned int	_position;

	//void			_calibrateFinger(void);
	void			_setPosition(unsigned int);

public:

	Motor(void);
	Motor(Motor const &);
	Motor	&operator=(Motor const &);
	~Motor(void);

	unsigned int	getPosition(void) const;
	void			smoothMove(unsigned int);	//	Constant speed
	void			smartMove(unsigned int);	//	Start slow, speed up, slow down
	void			fastMove(unsigned int);		//	Max speed
};

#endif
