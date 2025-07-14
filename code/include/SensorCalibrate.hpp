#ifndef SENSORCALIBRATE_HPP
#define SENSORCALIBRATE_HPP

#include <util/delay.h>
#include "Arm.hpp"

#define SENSOR_MAX 0xffff

class SensorCalibrate {
   public:
	SensorCalibrate(Arm& a);
	uint8_t calibrate();

   private:
	void	 setMinMax(Finger* f, uint8_t idx);
	uint8_t	 calibrateFinger(Finger* f, uint8_t idx);
	Arm		 arm;
	uint16_t min[5];
	uint16_t max[5];
};

#endif
