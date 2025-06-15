#ifndef MOTOR_INDEX_HPP
#define MOTOR_INDEX_HPP

#include "Motor.hpp"

class MotorIndex : public Motor {
   public:
	MotorIndex();
	MotorIndex(MotorIndex const& m);
	~MotorIndex();
	MotorIndex& operator=(MotorIndex const& m);

	uint16_t getPosition();
	void	 setPosition(uint16_t pos);

   private:
};

#endif
