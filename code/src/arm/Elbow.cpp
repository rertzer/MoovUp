#include "Elbow.hpp"

Elbow::Elbow() : Joint(elbow_pos_min, elbow_pos_max, inverted), motor() {}

Elbow::Elbow(Elbow const& e) : Joint(e.pos_min, e.pos_max, e.motor_inverted) {
	*this = e;
}
Elbow::~Elbow() {}

Elbow& Elbow::operator=(Elbow const& e) {
	if (this != &e) {
		Joint::operator=(e);
		motor = e.motor;
	}
	return (*this);
}

void Elbow::moveUp() {
	updatePos();
	motor.setPosition(pos);
}
const uint16_t Elbow::elbow_pos_min = 500;
const uint16_t Elbow::elbow_pos_max = 2500;
const bool	   Elbow::inverted = false;
