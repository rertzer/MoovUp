#include "Elbow.hpp"

Elbow::Elbow() : Joint(500, 2500), motor() {}

Elbow::Elbow(Elbow const& e) : Joint(e.pos_min, e.pos_max) {
	*this = e;
}
Elbow::~Elbow() {}

Elbow& Elbow::operator=(Elbow const& e) {
	if (this != &e) {
		pos = e.pos;
		target = e.target;
		speed = e.speed;
	}
	return (*this);
}

void Elbow::moveUp() {
	if (pos < target) {
		pos += speed;
		if (pos > target) {
			pos = target;
		}
	} else if (pos > target) {
		pos -= speed;
		if (pos < target) {
			pos = target;
		}
	}
	motor.setPosition(pos);
}
