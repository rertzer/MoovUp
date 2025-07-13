#include "Shoulder.hpp"

Shoulder::Shoulder() : Joint(shoulder_pos_min, shoulder_pos_max, inverted), motor() {
	setTarget(150);
}

Shoulder::Shoulder(Shoulder const& s) : Joint(s.pos_min, s.pos_max, s.motor_inverted) {
	*this = s;
}

Shoulder::~Shoulder() {}

Shoulder& Shoulder::operator=(Shoulder const& s) {
	if (this != &s) {
		Joint::operator=(s);
		motor = s.motor;
	}
	return (*this);
}

void Shoulder::moveUp() {
	updatePos();
	motor.setPosition(pos);
}
const uint16_t Shoulder::shoulder_pos_min = 500;
const uint16_t Shoulder::shoulder_pos_max = 1600;
const bool	   Shoulder::inverted = false;
