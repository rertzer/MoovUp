#ifndef INDEX_HPP
#define INDEX_HPP

#include "MotorIndex.hpp"
#include "body.hpp"
#include "hallSensor.hpp"

class Index {
   public:
	Index();
	Index(Index const& m);
	~Index();
	Index& operator=(Index const& m);

	uint16_t getPosition();
	uint16_t getTarget();
	void	 setTarget(uint16_t t);
	uint16_t getSpeed();
	void	 setSpeed(uint16_t s);
	MoveMode getMode();
	void	 setMode(MoveMode m);
	void	 moveUp();

   private:
	MotorIndex motor;
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
