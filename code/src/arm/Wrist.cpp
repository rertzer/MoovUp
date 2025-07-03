#include "Wrist.hpp"

Wrist::Wrist() : Joint(500, 2500), motor() {}

Wrist::Wrist(Wrist const& w) : Joint(w.pos_min, w.pos_max) {
	*this = w;
}

Wrist::~Wrist() {}

Wrist& Wrist::operator=(Wrist const& w) {
	if (this != &w) {
		pos_min = w.pos_min;
		pos_max = w.pos_max;
		pos = w.pos;
		target = w.target;
		speed = w.speed;
	}
	return (*this);
}

void Wrist::moveUp() {
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
