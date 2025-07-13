#ifndef MOTOR_RING_HPP
#define MOTOR_RING_HPP

#include "Motor.hpp"

class MotorRing : public Motor {
   public:
	MotorRing(uint16_t start_pos);
	MotorRing(MotorRing const& m);
	~MotorRing();
	MotorRing& operator=(MotorRing const& m);

	uint16_t getPosition() const;
	void	 setPosition(uint16_t pos);

   private:
};

#endif
