#ifndef SHOULDER_HPP
#define SHOULDER_HPP

#include "Joint.hpp"
#include "MotorShoulder.hpp"

class Shoulder : public Joint {
   public:
	Shoulder();
	Shoulder(Shoulder const& s);
	~Shoulder();
	Shoulder& operator=(Shoulder const& s);

	void moveUp();

   private:
	MotorShoulder		  motor;
	static const uint16_t shoulder_pos_min;
	static const uint16_t shoulder_pos_max;
	static const bool	  inverted;
};

#endif
