#ifndef FINGER_HPP
#define FINGER_HPP

#include "Joint.hpp"
#include "hallSensor.hpp"

enum class MoveMode { POSITION, PRESSURE };
enum class PressureLevel { BASE, LIGHT, MILD, HIGH };

class Finger : public Joint {
   public:
	Finger(uint8_t sensor_pin, motor_setup_t ms);
	Finger(Finger const& m);
	~Finger();
	Finger& operator=(Finger const& m);

	uint16_t	  getPressure() const;
	PressureLevel getPressureLevel() const;
	uint16_t	  getPressureBase() const;
	void		  setPressureBase(uint16_t base);
	uint16_t	  getPressureTarget() const;
	void		  setPressureTarget(uint16_t p);
	MoveMode	  getMode() const;
	void		  setMode(MoveMode m);
	virtual void  move() = 0;

   protected:
	Hall	 sensor;
	uint16_t pressure_base;
	uint16_t pressure_target;
	MoveMode mode;
};

#endif
