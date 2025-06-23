#include "Thumb.hpp"
#include "body.hpp"

Thumb::Thumb()
	: motor(), sensor(2), pos_min(500), pos_max(2500), pos(0), target(0), speed(0), mode(MoveMode::POSITION) {}

Thumb::Thumb(Thumb const& t) : sensor(t.sensor.getPin()) {
	*this = t;
}
Thumb::~Thumb() {}

Thumb& Thumb::operator=(Thumb const& t) {
	if (this != &t) {
		pos = t.pos;
		target = t.target;
		speed = t.speed;
		mode = t.mode;
	}
	return (*this);
}

uint16_t Thumb::degre2pos(uint16_t deg) {
	uint16_t p = deg * 100 / 9;
	p += 500;
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	return (p);
}

uint16_t Thumb::pos2degre(uint16_t p) {
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	p -= 500;
	return (p * 9 / 100);
}

uint16_t Thumb::getPosition() {
	return (pos2degre(pos));
}

uint16_t Thumb::getTarget() {
	return (pos2degre(target));
}

void Thumb::setTarget(uint16_t t) {
	target = degre2pos(t);
}

uint16_t Thumb::getSpeed() {
	return (pos2degre(speed));
}

void Thumb::setSpeed(uint16_t s) {
	speed = degre2pos(s);
}

MoveMode Thumb::getMode() {
	return (mode);
}

void Thumb::setMode(MoveMode m) {
	mode = m;
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
