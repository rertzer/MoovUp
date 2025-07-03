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

	void moveUp();

   private:
	MotorRing motor;
};

#endif
