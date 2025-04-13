/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arm.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:03:57 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/11 19:23:59 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARM_HPP
# define ARM_HPP

# include "Hand.hpp"

enum	e_armPos
{
	E_ARM_GRAB_POS,	// = some PWM value
	E_ARM_SERV_POS	// = some PWM value
};

class Arm
{
	Hand	_hand;

public:

	Arm(void);
	Arm(Arm const &);
	Arm &operator=(Arm const &);
	~Arm(void);

	Hand	getHand(void) const;

	void	init(void) const;
	void	move(unsigned int const) const;
};

#endif
