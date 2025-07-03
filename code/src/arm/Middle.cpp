#include "Middle.hpp"

Middle::Middle() : Finger(3, 500, 2500), motor() {}

Middle::Middle(Middle const& m) : Finger(m.sensor.getPin(), m.pos_min, m.pos_max) {
	*this = m;
}

Middle::~Middle() {}

Middle& Middle::operator=(Middle const& m) {
	if (this != &m) {
		pos_min = m.pos_min;
		pos_max = m.pos_max;
		pos = m.pos;
		target = m.target;
		speed = m.speed;
		mode = m.mode;
	}
	return (*this);
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
