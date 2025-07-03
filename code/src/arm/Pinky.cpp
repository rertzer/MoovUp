#include "Pinky.hpp"

Pinky::Pinky() : Finger(5, 500, 2500), motor() {}

Pinky::Pinky(Pinky const& p) : Finger(p.sensor.getPin(), p.pos_min, p.pos_max) {
	*this = p;
}

Pinky::~Pinky() {}

Pinky& Pinky::operator=(Pinky const& p) {
	if (this != &p) {
		pos_min = p.pos_min;
		pos_max = p.pos_max;
		pos = p.pos;
		target = p.target;
		speed = p.speed;
		mode = p.mode;
	}
	return (*this);
}

void Pinky::moveUp() {
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
