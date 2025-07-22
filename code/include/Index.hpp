#ifndef INDEX_HPP
#define INDEX_HPP

#include "Finger.hpp"
#include "MotorIndex.hpp"

class Index : public Finger {
   public:
	Index();
	Index(Index const& m);
	~Index();
	Index& operator=(Index const& m);

	void move();
	void reset();

   private:
	MotorIndex					   motor;
	static constexpr uint8_t	   sensor_pin{2};
	static constexpr motor_setup_t motor_default{Joint::pwm_min, Joint::pwm_max, Joint::pwm_max, true};
};

#endif
