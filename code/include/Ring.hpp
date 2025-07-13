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
	MotorRing				   motor;
	static const uint8_t	   sensor_pin;
	static const motor_setup_t motor_default;
};

#endif
