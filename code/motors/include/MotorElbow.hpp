#ifndef MOTOR_ELBOW_HPP
#define MOTOR_ELBOW_HPP

#include "Motor.hpp"

class MotorElbow : public Motor {
   public:
	MotorElbow();
	MotorElbow(MotorElbow const& m);
	~MotorElbow();
	MotorElbow& operator=(MotorElbow const& m);

	uint16_t getPosition();
	void	 setPosition(uint16_t pos);

   private:
};

#endif
