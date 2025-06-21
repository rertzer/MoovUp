#include "Shoulder.hpp"
#include "body.hpp"

Shoulder::Shoulder()
	: motor(), sensor(2), pos_min(500), pos_max(1400), pos(0), target(1500), speed(0), mode(MoveMode::POSITION) {}
//
// Shoulder::Shoulder(Shoulder const& i) {
// 	*this = i;
// }
Shoulder::~Shoulder() {}

Shoulder& Shoulder::operator=(Shoulder const& i) {
	if (this != &i) {
		pos = i.pos;
		target = i.target;
		speed = i.speed;
		mode = i.mode;
	}
	return (*this);
}

uint16_t Shoulder::degre2pos(uint16_t deg) {
	uint16_t p = deg * 100 / 9;
	p += 500;
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	return (p);
}

uint16_t Shoulder::pos2degre(uint16_t p) {
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	p -= 500;
	return (p * 9 / 100);
}

uint16_t Shoulder::getPosition() {
	return (pos2degre(pos));
}

uint16_t Shoulder::getTarget() {
	return (pos2degre(target));
}

void Shoulder::setTarget(uint16_t t) {
	target = degre2pos(t);
}

uint16_t Shoulder::getSpeed() {
	return (pos2degre(speed));
}

void Shoulder::setSpeed(uint16_t s) {
	speed = degre2pos(s);
}

MoveMode Shoulder::getMode() {
	return (mode);
}

void Shoulder::setMode(MoveMode m) {
	mode = m;
}

void Shoulder::moveUp() {
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
