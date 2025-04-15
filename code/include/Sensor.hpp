/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sensor.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:24:15 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/15 17:36:55 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SENSOR_HPP
# define SENSOR_HPP

class Sensor
{
	unsigned int	_pressure;
	//unsigned int	_minPressure;
	//unsigned int	_maxPressure;

public:

	Sensor(void);
	Sensor(Sensor const &);
	Sensor	&operator=(Sensor const &);
	~Sensor(void);

	unsigned int	getPressure(void) const volatile;
	void			setPressure(unsigned int);
	//void			calibrateSensor(void);	//	Saving min and max pressures read during the calibration timing to adapt limit pressures (depending on glass shape).
											//	P1, P2, P3, ... should be a percentage of min, max values.
};

#endif
