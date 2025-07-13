#ifndef WRIST_HPP
#define WRIST_HPP

#include "Joint.hpp"
#include "MotorWrist.hpp"

class Wrist : public Joint {
   public:
	Wrist();
	Wrist(Wrist const& w);
	~Wrist();
	Wrist& operator=(Wrist const& w);

	void moveUp();

   private:
	MotorWrist				   motor;
	static const motor_setup_t motor_default;
};

#endif
