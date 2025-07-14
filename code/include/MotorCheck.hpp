#ifndef MOTOR_CHECK_HPP
#define MOTOR_CHECK_HPP

#include <util/delay.h>
#include "Arm.hpp"

class MotorCheck {
   public:
	MotorCheck(Arm& a);
	void run();
	void reset();
	void jointTest(char const* name, Joint* joint);

   private:
	Arm arm;
};

#endif
