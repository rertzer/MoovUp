#include "Shoulder.hpp"

Shoulder::Shoulder() : Joint(500, 1400), motor() {}

Shoulder::Shoulder(Shoulder const& s) : Joint(s.pos_min, s.pos_max) {
	*this = s;
}

Shoulder::~Shoulder() {}

Shoulder& Shoulder::operator=(Shoulder const& s) {
	if (this != &s) {
		pos_min = s.pos_min;
		pos_max = s.pos_max;
		pos = s.pos;
		target = s.target;
		speed = s.speed;
	}
	return (*this);
}

void Shoulder::moveUp() {
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
