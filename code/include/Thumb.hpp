#ifndef THUMB_HPP
#define THUMB_HPP

#include "Finger.hpp"
#include "MotorThumb.hpp"

class Thumb : public Finger {
   public:
	Thumb();
	Thumb(Thumb const& m);
	~Thumb();
	Thumb& operator=(Thumb const& m);

	void move();
	void reset();

   private:
	MotorThumb					   motor;
	static constexpr uint8_t	   sensor_pin{1};
	static constexpr motor_setup_t motor_default{Joint::pwm_min, Joint::pwm_max, Joint::pwm_max, true};
};

#endif
