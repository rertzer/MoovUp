#include "Elbow.hpp"

Elbow::Elbow() : motor(), sensor(2), pos_min(500), pos_max(2500), pos(0), target(0), speed(0) {}

Elbow::Elbow(Elbow const& e) : sensor(e.sensor.getPin()) {
	*this = e;
}
Elbow::~Elbow() {}

Elbow& Elbow::operator=(Elbow const& i) {
	if (this != &i) {
		pos = i.pos;
		target = i.target;
		speed = i.speed;
	}
	return (*this);
}

uint16_t Elbow::degre2pos(uint16_t deg) {
	uint16_t p = deg * 100 / 9;
	p += 500;
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	return (p);
}

uint16_t Elbow::pos2degre(uint16_t p) {
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	p -= 500;
	return (p * 9 / 100);
}

uint16_t Elbow::getPosition() {
	return (pos2degre(pos));
}

uint16_t Elbow::getTarget() {
	return (pos2degre(target));
}

void Elbow::setTarget(uint16_t t) {
	target = degre2pos(t);
}

uint16_t Elbow::getSpeed() {
	return (pos2degre(speed));
}

void Elbow::setSpeed(uint16_t s) {
	speed = degre2pos(s);
}

void Elbow::moveUp() {
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
