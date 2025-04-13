/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Finger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:43:40 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/11 18:49:59 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FINGER_HPP
# define FINGER_HPP

enum	e_finger
{
	E_THUMB,
	E_INDEX,
	E_MIDDLE,
	E_RING,
	E_PINKY
};

class 	Finger
{
	//_calibrateFinger(void);
	volatile int		_pressure;		//	Volatile, because pressure is going to be monitored constantly and set accordingly?

public:

	Finger(void);
	Finger(Finger const &);
	Finger	&operator=(Finger const &);
	~Finger(void);

	int		getPressure(void) const;
	void	setPressure(void);
	void	move(unsigned int const) const;
	void	init(void) const;
};

#endif
