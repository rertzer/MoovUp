#ifndef PINKY_HPP
#define PINKY_HPP

#include "Finger.hpp"
#include "MotorPinky.hpp"

class Pinky : public Finger {
   public:
	Pinky();
	Pinky(Pinky const& p);
	~Pinky();
	Pinky& operator=(Pinky const& p);
	void   move();
	void   reset();

   private:
	MotorPinky					   motor;
	static constexpr uint8_t	   sensor_pin{5};
	static constexpr motor_setup_t motor_default{Joint::pwm_min, Joint::pwm_max, Joint::pwm_min, false};
};

#endif
