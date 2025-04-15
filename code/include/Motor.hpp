/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Motor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:58:53 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/15 16:52:57 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOTOR_HPP
# define MOTOR_HPP

# define ARM_SERV_POS
# define ARM_GRAB_POS

# define THUMB	0
# define INDEX	1
# define MIDDLE	2
# define RING	3
# define PINKY	4

# define WRIST	5

# define ARM	6

# define P1		42424242	//	Define proper names
# define P2		42424242	//	Define proper names
# define P3		42424242	//	Define proper names
# define P4		42424242	//	Define proper names
# define P5		42424242	//	Define proper names

# define THUMB_OPEN_POS		42424242
# define THUMB_CLOSED_POS	42424242

# define RING_OPEN_POS		42424242
# define RING_CLOSED_POS	42424242

# define PINKY_OPEN_POS		42424242
# define PINKY_CLOSED_POS	42424242

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
	void			smoothMove(unsigned int, unsigned int);	//	Constant speed with sensor threshold value to test continuously
	void			smartMove(unsigned int);	//	Start slow, speed up, slow down
	void			fastMove(unsigned int);		//	Max speed
};

#endif
