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
	MotorElbow						  motor;
	static const Joint::motor_setup_t motor_default;
};

#endif
