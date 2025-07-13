#ifndef MOTOR_PINKY_HPP
#define MOTOR_PINKY_HPP

#include "Motor.hpp"

class MotorPinky : public Motor {
   public:
	MotorPinky(uint16_t start_pos);
	MotorPinky(MotorPinky const& m);
	~MotorPinky();
	MotorPinky& operator=(MotorPinky const& m);

	uint16_t getPosition() const;
	void	 setPosition(uint16_t pos);

   private:
};

#endif
