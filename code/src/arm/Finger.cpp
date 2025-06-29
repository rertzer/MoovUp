#include "Finger.hpp"
#include "arm.hpp"

Finger::Finger(uint8_t sensor_pin, uint16_t p_min, uint16_t p_max)
	: sensor(sensor_pin), pos_min(p_min), pos_max(p_max), pos(0), target(0), speed(0), mode(MoveMode::POSITION) {}

Finger::Finger(Finger const& i) : sensor(i.sensor.getPin()) {
	*this = i;
}

Finger::~Finger() {}

Finger& Finger::operator=(Finger const& i) {
	if (this != &i) {
		pos = i.pos;
		target = i.target;
		speed = i.speed;
		mode = i.mode;
	}
	return (*this);
}

uint16_t Finger::degre2pos(uint16_t deg) {
	uint16_t p = deg * 100 / 9;
	p += 500;
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	return (p);
}

uint16_t Finger::pos2degre(uint16_t p) {
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	p -= 500;
	return (p * 9 / 100);
}

uint16_t Finger::getPosition() {
	return (pos2degre(pos));
}

uint16_t Finger::getTarget() {
	return (pos2degre(target));
}

void Finger::setTarget(uint16_t t) {
	target = degre2pos(t);
}

uint16_t Finger::getSpeed() {
	return (pos2degre(speed));
}

void Finger::setSpeed(uint16_t s) {
	speed = degre2pos(s);
}

MoveMode Finger::getMode() {
	return (mode);
}

void Finger::setMode(MoveMode m) {
	mode = m;
}

void Finger::updatePos() {
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
