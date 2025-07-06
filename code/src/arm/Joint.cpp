#include "Joint.hpp"

Joint::Joint(uint16_t p_min, uint16_t p_max) : pos_min(p_min), pos_max(p_max), pos(0), target(0), speed(0) {}

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
	}
	return (*this);
}

uint16_t Joint::degre2pos(uint16_t deg) const {
	uint16_t p = deg * 100 / 9;
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
	p -= 500;
	return (p * 9 / 100);
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
	return (pos2degre(speed));
}

void Joint::setSpeed(uint16_t s) {
	speed = degre2pos(s);
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
