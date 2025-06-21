#ifndef WRIST_HPP
#define WRIST_HPP

#include "MotorWrist.hpp"
#include "body.hpp"
#include "hallSensor.hpp"

// extern uint8_t	g_pinToBit[];
// extern uint8_t	g_pinToPort[];
// extern uint16_t g_portToMode[];
// extern uint16_t g_portToOutput[];

class Wrist {
   public:
	Wrist();
	Wrist(Wrist const& m);
	~Wrist();
	Wrist& operator=(Wrist const& m);

	uint16_t getPosition();
	uint16_t getTarget();
	void	 setTarget(uint16_t t);
	uint16_t getSpeed();
	void	 setSpeed(uint16_t s);
	MoveMode getMode();
	void	 setMode(MoveMode m);
	void	 moveUp();

   private:
	MotorWrist motor;
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
