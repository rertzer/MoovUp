#ifndef MOTOR_WRIST_HPP
#define MOTOR_WRIST_HPP

#include "Motor.hpp"

class MotorWrist : public Motor {
   public:
	MotorWrist();
	MotorWrist(MotorWrist const& m);
	~MotorWrist();
	MotorWrist& operator=(MotorWrist const& m);

	uint16_t getPosition();
	void	 setPosition(uint16_t pos);

   private:
};

#endif
