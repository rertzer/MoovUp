#include "Ring.hpp"

Ring::Ring() : Finger(sensor_pin, ring_pos_min, ring_pos_max, inverted), motor() {}

Ring::Ring(Ring const& r) : Finger(r.sensor.getPin(), r.pos_min, r.pos_max, r.motor_inverted) {
	*this = r;
}

Ring::~Ring() {}

Ring& Ring::operator=(Ring const& r) {
	if (this != &r) {
		Finger::operator=(r);
		motor = r.motor;
	}
	return (*this);
}

void Ring::moveUp() {
	updatePos();
	motor.setPosition(pos);
}

const uint8_t  Ring::sensor_pin = 4;
const uint16_t Ring::ring_pos_min = 500;
const uint16_t Ring::ring_pos_max = 2500;
const bool	   Ring::inverted = false;
