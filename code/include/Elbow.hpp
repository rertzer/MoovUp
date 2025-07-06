#ifndef ELBOW_HPP
#define ELBOW_HPP

#include "Joint.hpp"
#include "MotorElbow.hpp"

class Elbow : public Joint {
   public:
	Elbow();
	Elbow(Elbow const& m);
	~Elbow();
	Elbow& operator=(Elbow const& m);

	void moveUp();

   private:
	MotorElbow			  motor;
	static const uint16_t elbow_pos_min;
	static const uint16_t elbow_pos_max;
};

#endif
