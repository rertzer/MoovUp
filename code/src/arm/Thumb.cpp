#include "Thumb.hpp"

Thumb::Thumb() : Finger(sensor_pin, thumb_pos_min, thumb_pos_max), motor() {}

Thumb::Thumb(Thumb const& t) : Finger(t.sensor.getPin(), t.pos_min, t.pos_max) {
	*this = t;
}
Thumb::~Thumb() {}

Thumb& Thumb::operator=(Thumb const& t) {
	if (this != &t) {
		Finger::operator=(t);
		motor = t.motor;
	}
	return (*this);
}

uint16_t Thumb::degre2pos(uint16_t deg) {
	deg = 180 - deg;
	return (Joint::degre2pos(deg));
}

uint16_t Thumb::pos2degre(uint16_t p) {
	if (p < pos_min) {
		p = pos_min;
	} else if (p > pos_max) {
		p = pos_max;
	}
	p -= 500;
	p = p * 9 / 100;
	return (180 - p);
}

void Thumb::moveUp() {
	updatePos();
	motor.setPosition(pos);
}

const uint8_t  Thumb::sensor_pin = 1;
const uint16_t Thumb::thumb_pos_min = 500;
const uint16_t Thumb::thumb_pos_max = 2500;
