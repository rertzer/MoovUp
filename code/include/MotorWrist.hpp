#ifndef MOTOR_WRIST_HPP
#define MOTOR_WRIST_HPP

#include "Motor.hpp"

class MotorWrist : public Motor {
   public:
	MotorWrist(uint16_t start_pos);
	MotorWrist(MotorWrist const& m);
	~MotorWrist();
	MotorWrist& operator=(MotorWrist const& m);

	uint16_t getPosition() const;
	void	 setPosition(uint16_t pos);

   private:
};

#endif
