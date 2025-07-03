#include "Thumb.hpp"

Thumb::Thumb() : Finger(1, 500, 2500), motor() {}

Thumb::Thumb(Thumb const& t) : Finger(t.sensor.getPin(), t.pos_min, t.pos_max) {
	*this = t;
}
Thumb::~Thumb() {}

Thumb& Thumb::operator=(Thumb const& t) {
	if (this != &t) {
		pos_min = t.pos_min;
		pos_max = t.pos_max;
		pos = t.pos;
		target = t.target;
		speed = t.speed;
		mode = t.mode;
	}
	return (*this);
}

uint16_t Thumb::degre2pos(uint16_t deg) {
	deg = 180 - deg;
	return (Joint::degre2pos(deg));
}

uint16_t Thumb::pos2degre(uint16_t p) {
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	p -= 500;
	p = p * 9 / 100;
	return (180 - p);
}

void Thumb::moveUp() {
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
