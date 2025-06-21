#include "Wrist.hpp"
#include "body.hpp"

Wrist::Wrist()
	: motor(), sensor(2), pos_min(500), pos_max(2500), pos(0), target(0), speed(0), mode(MoveMode::POSITION) {}
//
// Wrist::Wrist(Wrist const& i) {
// 	*this = i;
// }
Wrist::~Wrist() {}

Wrist& Wrist::operator=(Wrist const& i) {
	if (this != &i) {
		pos = i.pos;
		target = i.target;
		speed = i.speed;
		mode = i.mode;
	}
	return (*this);
}

uint16_t Wrist::degre2pos(uint16_t deg) {
	uint16_t p = deg * 100 / 9;
	p += 500;
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	return (p);
}

uint16_t Wrist::pos2degre(uint16_t p) {
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	p -= 500;
	return (p * 9 / 100);
}

uint16_t Wrist::getPosition() {
	return (pos2degre(pos));
}

uint16_t Wrist::getTarget() {
	return (pos2degre(target));
}

void Wrist::setTarget(uint16_t t) {
	target = degre2pos(t);
}

uint16_t Wrist::getSpeed() {
	return (pos2degre(speed));
}

void Wrist::setSpeed(uint16_t s) {
	speed = degre2pos(s);
}

MoveMode Wrist::getMode() {
	return (mode);
}

void Wrist::setMode(MoveMode m) {
	mode = m;
}

void Wrist::moveUp() {
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
