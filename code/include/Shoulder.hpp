#ifndef SHOULDER_HPP
#define SHOULDER_HPP

#include "Joint.hpp"
#include "MotorShoulder.hpp"

class Shoulder : public Joint {
   public:
	Shoulder();
	Shoulder(Shoulder const& s);
	~Shoulder();
	Shoulder& operator=(Shoulder const& s);

	void move();
	void reset();

   private:
	MotorShoulder				   motor;
	static constexpr motor_setup_t motor_default{Joint::pwm_min, 1600, 1472, false};
};

#endif
