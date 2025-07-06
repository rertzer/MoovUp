#ifndef MOTOR_SHOULDER_HPP
#define MOTOR_SHOULDER_HPP

#include "Motor.hpp"

class MotorShoulder : public Motor {
   public:
	MotorShoulder();
	MotorShoulder(MotorShoulder const& m);
	~MotorShoulder();
	MotorShoulder& operator=(MotorShoulder const& m);

	uint16_t getPosition() const;
	void	 setPosition(uint16_t pos);

   private:
};

#endif
