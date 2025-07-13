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

	void moveUp();

   private:
	MotorThumb				   motor;
	static const uint8_t	   sensor_pin;
	static const motor_setup_t motor_default;
};

#endif
