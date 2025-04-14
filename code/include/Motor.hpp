/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Motor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:58:53 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/14 19:11:54 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOTOR_HPP
# define MOTOR_HPP

# define ARM_SERV_POS
# define ARM_GRAB_POS

class Motor
{
	unsigned int	_position;

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
