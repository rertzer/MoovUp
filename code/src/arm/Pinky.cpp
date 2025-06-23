#include "Pinky.hpp"
#include "body.hpp"

Pinky::Pinky()
	: motor(), sensor(2), pos_min(500), pos_max(2500), pos(0), target(0), speed(0), mode(MoveMode::POSITION) {}

Pinky::Pinky(Pinky const& p) : sensor(p.sensor.getPin()) {
	*this = p;
}

Pinky::~Pinky() {}

Pinky& Pinky::operator=(Pinky const& p) {
	if (this != &p) {
		pos = p.pos;
		target = p.target;
		speed = p.speed;
		mode = p.mode;
	}
	return (*this);
}

uint16_t Pinky::degre2pos(uint16_t deg) {
	uint16_t p = deg * 100 / 9;
	p += 500;
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	return (p);
}

uint16_t Pinky::pos2degre(uint16_t p) {
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	p -= 500;
	return (p * 9 / 100);
}

uint16_t Pinky::getPosition() {
	return (pos2degre(pos));
}

uint16_t Pinky::getTarget() {
	return (pos2degre(target));
}

void Pinky::setTarget(uint16_t t) {
	target = degre2pos(t);
}

uint16_t Pinky::getSpeed() {
	return (pos2degre(speed));
}

void Pinky::setSpeed(uint16_t s) {
	speed = degre2pos(s);
}

MoveMode Pinky::getMode() {
	return (mode);
}

void Pinky::setMode(MoveMode m) {
	mode = m;
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
