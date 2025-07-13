#ifndef MOTOR_MIDDLE_HPP
#define MOTOR_MIDDLE_HPP

#include "Motor.hpp"

class MotorMiddle : public Motor {
   public:
	MotorMiddle(uint16_t start_pos);
	MotorMiddle(MotorMiddle const& m);
	~MotorMiddle();
	MotorMiddle& operator=(MotorMiddle const& m);

	uint16_t getPosition() const;
	void	 setPosition(uint16_t pos);

   private:
};

#endif
