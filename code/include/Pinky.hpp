#ifndef PINKY_HPP
#define PINKY_HPP

#include "MotorPinky.hpp"
#include "body.hpp"
#include "hallSensor.hpp"

// extern uint8_t	g_pinToBit[];
// extern uint8_t	g_pinToPort[];
// extern uint16_t g_portToMode[];
// extern uint16_t g_portToOutput[];

class Pinky {
   public:
	Pinky();
	Pinky(Pinky const& m);
	~Pinky();
	Pinky& operator=(Pinky const& m);

	uint16_t getPosition();
	uint16_t getTarget();
	void	 setTarget(uint16_t t);
	uint16_t getSpeed();
	void	 setSpeed(uint16_t s);
	MoveMode getMode();
	void	 setMode(MoveMode m);
	void	 moveUp();

   private:
	MotorPinky motor;
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
