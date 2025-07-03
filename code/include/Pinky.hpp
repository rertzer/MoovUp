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
	MotorPinky motor;
};

#endif
