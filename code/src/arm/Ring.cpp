#include "Ring.hpp"
#include "body.hpp"

Ring::Ring() : motor(), sensor(2), pos_min(500), pos_max(2500), pos(0), target(0), speed(0), mode(MoveMode::POSITION) {}

Ring::Ring(Ring const& r) : sensor(r.sensor.getPin()) {
	*this = r;
}

Ring::~Ring() {}

Ring& Ring::operator=(Ring const& r) {
	if (this != &r) {
		pos = r.pos;
		target = r.target;
		speed = r.speed;
		mode = r.mode;
	}
	return (*this);
}

uint16_t Ring::degre2pos(uint16_t deg) {
	uint16_t p = deg * 100 / 9;
	p += 500;
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	return (p);
}

uint16_t Ring::pos2degre(uint16_t p) {
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	p -= 500;
	return (p * 9 / 100);
}

uint16_t Ring::getPosition() {
	return (pos2degre(pos));
}

uint16_t Ring::getTarget() {
	return (pos2degre(target));
}

void Ring::setTarget(uint16_t t) {
	target = degre2pos(t);
}

uint16_t Ring::getSpeed() {
	return (pos2degre(speed));
}

void Ring::setSpeed(uint16_t s) {
	speed = degre2pos(s);
}

MoveMode Ring::getMode() {
	return (mode);
}

void Ring::setMode(MoveMode m) {
	mode = m;
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
