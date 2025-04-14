/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Motor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:58:53 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/14 15:03:22 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOTOR_HPP
# define MOTOR_HPP

class Motor
{
	unsigned int	_position;

public:

	Motor(void);
	Motor(Motor const &);
	Motor	&operator=(Motor const &);
	~Motor(void);

	unsigned int	getPosition(void) const;
	void			setPosition(unsigned int);
};

#endif
