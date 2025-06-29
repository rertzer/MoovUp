#ifndef RING_HPP
#define RING_HPP

#include "MotorRing.hpp"
#include "arm.hpp"
#include "hallSensor.hpp"

class Ring {
   public:
	Ring();
	Ring(Ring const& m);
	~Ring();
	Ring& operator=(Ring const& m);

	uint16_t getPosition();
	uint16_t getTarget();
	void	 setTarget(uint16_t t);
	uint16_t getSpeed();
	void	 setSpeed(uint16_t s);
	MoveMode getMode();
	void	 setMode(MoveMode m);
	void	 moveUp();

   private:
	MotorRing motor;
	Hall	  sensor;
	uint16_t  degre2pos(uint16_t deg);
	uint16_t  pos2degre(uint16_t pos);
	uint16_t  pos_min;
	uint16_t  pos_max;
	uint16_t  pos;
	uint16_t  target;
	uint16_t  speed;
	MoveMode  mode;
};

#endif
