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
	void   moveUp();

   private:
	MotorPinky			  motor;
	static const uint8_t  sensor_pin;
	static const uint16_t pinky_pos_min;
	static const uint16_t pinky_pos_max;
	static const bool	  inverted;
};

#endif
