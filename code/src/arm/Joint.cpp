#include "Joint.hpp"
#include "Uart.hpp"

extern Uart uart;

Joint::Joint(motor_setup_t ms) : motor_setup(ms), pos(ms.start), target(ms.start), speed(0) {}

Joint::Joint(Joint const& j) {
	*this = j;
}

Joint::~Joint() {}

Joint& Joint::operator=(Joint const& j) {
	if (this != &j) {
		motor_setup = j.motor_setup;
		pos = j.pos;
		target = j.target;
		speed = j.speed;
	}
	return (*this);
}

uint16_t Joint::degre2pos(uint16_t deg) const {
	if (motor_setup.inverted) {
		deg = 180 - deg;
	}
	uint16_t p = deg * 100;
	p /= 9;
	p += 500;
	if (p < motor_setup.min) {
		p = motor_setup.min;
	} else if (p > motor_setup.max) {
		p = motor_setup.max;
	}
	return (p);
}
uint16_t Joint::pos2degre(uint16_t p) const {
	if (p < motor_setup.min) {
		p = motor_setup.min;
	} else if (p > motor_setup.max) {
		p = motor_setup.max;
	}
	p = (p - 500) * 9 / 100;
	if (motor_setup.inverted) {
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
