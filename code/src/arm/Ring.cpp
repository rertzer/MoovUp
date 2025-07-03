#include "Ring.hpp"

Ring::Ring() : Finger(4, 500, 2500), motor() {}

Ring::Ring(Ring const& r) : Finger(r.sensor.getPin(), r.pos_min, r.pos_max) {
	*this = r;
}

Ring::~Ring() {}

Ring& Ring::operator=(Ring const& r) {
	if (this != &r) {
		pos_min = r.pos_min;
		pos_max = r.pos_max;
		pos = r.pos;
		target = r.target;
		speed = r.speed;
		mode = r.mode;
	}
	return (*this);
}

void Ring::moveUp() {
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
