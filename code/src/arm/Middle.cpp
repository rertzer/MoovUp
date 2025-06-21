#include "Middle.hpp"
#include "body.hpp"

Middle::Middle()
	: motor(), sensor(2), pos_min(500), pos_max(2500), pos(0), target(0), speed(0), mode(MoveMode::POSITION) {}
//
// Middle::Middle(Middle const& i) {
// 	*this = i;
// }
Middle::~Middle() {}

Middle& Middle::operator=(Middle const& i) {
	if (this != &i) {
		pos = i.pos;
		target = i.target;
		speed = i.speed;
		mode = i.mode;
	}
	return (*this);
}

uint16_t Middle::degre2pos(uint16_t deg) {
	uint16_t p = deg * 100 / 9;
	p += 500;
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	return (p);
}

uint16_t Middle::pos2degre(uint16_t p) {
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	p -= 500;
	return (p * 9 / 100);
}

uint16_t Middle::getPosition() {
	return (pos2degre(pos));
}

uint16_t Middle::getTarget() {
	return (pos2degre(target));
}

void Middle::setTarget(uint16_t t) {
	target = degre2pos(t);
}

uint16_t Middle::getSpeed() {
	return (pos2degre(speed));
}

void Middle::setSpeed(uint16_t s) {
	speed = degre2pos(s);
}

MoveMode Middle::getMode() {
	return (mode);
}

void Middle::setMode(MoveMode m) {
	mode = m;
}

void Middle::moveUp() {
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
