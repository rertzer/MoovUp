#ifndef ELBOW_HPP
#define ELBOW_HPP

#include "Joint.hpp"
#include "MotorElbow.hpp"

class Elbow : public Joint {
   public:
	Elbow();
	Elbow(Elbow const& m);
	~Elbow();
	Elbow& operator=(Elbow const& m);

	void move();
	void reset();

   private:
	MotorElbow							  motor;
	static constexpr Joint::motor_setup_t motor_default{Joint::pwm_min, Joint::pwm_max, Joint::pwm_min, false};
};

#endif
