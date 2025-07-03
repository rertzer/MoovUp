#ifndef SHOULDER_HPP
#define SHOULDER_HPP

#include "MotorShoulder.hpp"
#include "hallSensor.hpp"

class Shoulder {
   public:
	Shoulder();
	Shoulder(Shoulder const& m);
	~Shoulder();
	Shoulder& operator=(Shoulder const& m);

	uint16_t getPosition();
	uint16_t getTarget();
	void	 setTarget(uint16_t t);
	uint16_t getSpeed();
	void	 setSpeed(uint16_t s);
	void	 moveUp();

   private:
	MotorShoulder motor;
	Hall		  sensor;
	uint16_t	  degre2pos(uint16_t deg);
	uint16_t	  pos2degre(uint16_t pos);
	uint16_t	  pos_min;
	uint16_t	  pos_max;
	uint16_t	  pos;
	uint16_t	  target;
	uint16_t	  speed;
};

#endif
