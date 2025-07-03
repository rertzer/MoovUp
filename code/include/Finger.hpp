#ifndef FINGER_HPP
#define FINGER_HPP

#include "arm.hpp"
#include "hallSensor.hpp"

class Finger {
   public:
	Finger(uint8_t sensor_pin, uint16_t pos_min, uint16_t pos_max);
	Finger(Finger const& m);
	~Finger();
	Finger& operator=(Finger const& m);

	uint16_t	 getPosition();
	uint16_t	 getTarget();
	void		 setTarget(uint16_t t);
	uint16_t	 getSpeed();
	void		 setSpeed(uint16_t s);
	MoveMode	 getMode();
	void		 setMode(MoveMode m);
	virtual void moveUp() = 0;

   protected:
	Hall	 sensor;
	uint16_t degre2pos(uint16_t deg);
	uint16_t pos2degre(uint16_t pos);
	void	 updatePos();
	uint16_t pos_min;
	uint16_t pos_max;
	uint16_t pos;
	uint16_t target;
	uint16_t speed;
	MoveMode mode;
};

#endif
