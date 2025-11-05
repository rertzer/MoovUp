#ifndef ARM_HPP
#define ARM_HPP

#include "Elbow.hpp"
#include "Index.hpp"
#include "Middle.hpp"
#include "Pinky.hpp"
#include "Ring.hpp"
#include "Shoulder.hpp"
#include "Thumb.hpp"
#include "Wrist.hpp"

class Arm {
   public:
	Elbow	 elbow;
	Index	 index;
	Middle	 middle;
	Pinky	 pinky;
	Ring	 ring;
	Shoulder shoulder;
	Thumb	 thumb;
	Wrist	 wrist;

	void move();
	void moveTrough();
	void setSpeed(uint16_t s);
	void reset();
	void exec(char* line);
	void shoulderLeft();
	void shoulderRight();
	void wristLeft();
	void wristRight();
	void handOpen();
	void handClose();
	void handGrab();
	void thumbOpen();
	void thumbClose();
	void indexOpen();
	void indexClose();
	void fingerOpen();
	void fingerClose();

   private:
};

#endif
