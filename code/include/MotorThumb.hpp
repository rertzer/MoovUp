#ifndef MOTOR_THUMB_HPP
#define MOTOR_THUMB_HPP

#include "Motor.hpp"

class MotorThumb : public Motor {
   public:
	MotorThumb();
	MotorThumb(MotorThumb const& m);
	~MotorThumb();
	MotorThumb& operator=(MotorThumb const& m);

	uint16_t getPosition() const;
	void	 setPosition(uint16_t pos);

   private:
};

#endif
