/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sensor.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:24:15 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/14 16:26:11 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SENSOR_HPP
# define SENSOR_HPP

class Sensor
{
	unsigned int	_pressure;

public:

	Sensor(void);
	Sensor(Sensor const &);
	Sensor	&operator=(Sensor const &);
	~Sensor(void);

	unsigned int	getPressure(void) const;
	void			setPressure(unsigned int);
};

#endif
