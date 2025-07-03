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

	void moveUp();

   private:
	MotorMiddle motor;
};

#endif
