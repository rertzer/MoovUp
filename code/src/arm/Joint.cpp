#include "Joint.hpp"
#include "Uart.hpp"

extern Uart uart;

Joint::Joint(uint16_t p_min, uint16_t p_max, bool mi)
	: pos_min(p_min), pos_max(p_max), pos(p_min), target(p_max), speed(0), motor_inverted(mi) {}

Joint::Joint(Joint const& j) {
	*this = j;
}

Joint::~Joint() {}

Joint& Joint::operator=(Joint const& j) {
	if (this != &j) {
		pos_min = j.pos_min;
		pos_max = j.pos_max;
		pos = j.pos;
		target = j.target;
		speed = j.speed;
		motor_inverted = j.motor_inverted;
	}
	return (*this);
}

uint16_t Joint::degre2pos(uint16_t deg) const {
	if (motor_inverted) {
		deg = 180 - deg;
	}
	uint16_t p = deg * 100;
	p /= 9;
	p += 500;
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	return (p);
}
uint16_t Joint::pos2degre(uint16_t p) const {
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	p = (p - 500) * 9 / 100;
	if (motor_inverted) {
		p = 180 - p;
	}
	return (p);
}

uint16_t Joint::getPosition() const {
	return (pos2degre(pos));
}

uint16_t Joint::getTarget() const {
	return (pos2degre(target));
}

void Joint::setTarget(uint16_t t) {
	target = degre2pos(t);
}

uint16_t Joint::getSpeed() const {
	return (speed);
}

void Joint::setSpeed(uint16_t s) {
	speed = s;
}

void Joint::updatePos() {
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
}
