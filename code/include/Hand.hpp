/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hand.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:58:57 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/14 14:58:06 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAND_HPP
# define HAND_HPP

# include "Finger.hpp"

class	Hand
{
	Motor	_motor[7];
	Sensor	_sensor[5];
	//	Pgm state enum

public:

	Hand(void);
	Hand(Hand const &);
	Hand	&operator=(Hand const &);
	~Hand(void);

	void	init(void) const;
	void	close(void) const;
	void	open(void) const;
	//	Animate hand
	//	Rock, paper, scissors
	//	..
};

#endif
