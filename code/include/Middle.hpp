#ifndef MIDDLE_HPP
#define MIDDLE_HPP

#include "Finger.hpp"
#include "MotorMiddle.hpp"

class Middle : public Finger {
   public:
	Middle();
	Middle(Middle const& m);
	~Middle();
	Middle& operator=(Middle const& m);

	void move();
	void reset();

   private:
	MotorMiddle					   motor;
	static constexpr uint8_t	   sensor_pin{3};
	static constexpr motor_setup_t motor_default{Joint::pwm_min, Joint::pwm_max, Joint::pwm_min, false};
};

#endif
