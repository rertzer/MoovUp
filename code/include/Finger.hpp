#ifndef FINGER_HPP
#define FINGER_HPP

#include "Joint.hpp"
#include "hallSensor.hpp"

enum class MoveMode { POSITION, PRESSURE };

class Finger : public Joint {
   public:
	Finger(uint8_t sensor_pin, uint16_t pos_min, uint16_t pos_max, bool mi);
	Finger(Finger const& m);
	~Finger();
	Finger& operator=(Finger const& m);

	uint16_t	 getPressureTarget() const;
	void		 setPressureTarget(uint16_t p);
	uint16_t	 getSensorValue() const;
	MoveMode	 getMode() const;
	void		 setMode(MoveMode m);
	virtual void moveUp() = 0;

   protected:
	Hall	 sensor;
	uint16_t pressure_target;
	MoveMode mode;
};

#endif
