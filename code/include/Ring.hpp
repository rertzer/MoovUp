#ifndef RING_HPP
#define RING_HPP

#include "Finger.hpp"
#include "MotorRing.hpp"

class Ring : public Finger {
   public:
	Ring();
	Ring(Ring const& m);
	~Ring();
	Ring& operator=(Ring const& m);

	void move();
	void reset();

   private:
	MotorRing					   motor;
	static constexpr uint8_t	   sensor_pin{4};
	static constexpr motor_setup_t motor_default{Joint::pwm_min, Joint::pwm_max, Joint::pwm_min, false};
};

#endif
