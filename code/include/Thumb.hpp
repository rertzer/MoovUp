#ifndef THUMB_HPP
#define THUMB_HPP

#include "MotorThumb.hpp"
#include "arm.hpp"
#include "hallSensor.hpp"

class Thumb {
   public:
	Thumb();
	Thumb(Thumb const& m);
	~Thumb();
	Thumb& operator=(Thumb const& m);

	uint16_t getPosition();
	uint16_t getTarget();
	void	 setTarget(uint16_t t);
	uint16_t getSpeed();
	void	 setSpeed(uint16_t s);
	MoveMode getMode();
	void	 setMode(MoveMode m);
	void	 moveUp();

   private:
	MotorThumb motor;
	Hall	   sensor;
	uint16_t   degre2pos(uint16_t deg);
	uint16_t   pos2degre(uint16_t pos);
	uint16_t   pos_min;
	uint16_t   pos_max;
	uint16_t   pos;
	uint16_t   target;
	uint16_t   speed;
	MoveMode   mode;
};

#endif
