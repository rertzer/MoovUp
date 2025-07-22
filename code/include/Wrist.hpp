#ifndef WRIST_HPP
#define WRIST_HPP

#include "Joint.hpp"
#include "MotorWrist.hpp"

class Wrist : public Joint {
   public:
	Wrist();
	Wrist(Wrist const& w);
	~Wrist();
	Wrist& operator=(Wrist const& w);

	void move();
	void reset();

   private:
	MotorWrist					   motor;
	static constexpr motor_setup_t motor_default{Joint::pwm_min, Joint::pwm_max, Joint::pwm_min, false};
};

#endif
