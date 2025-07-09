#include "Thumb.hpp"

Thumb::Thumb() : Finger(sensor_pin, thumb_pos_min, thumb_pos_max, inverted), motor() {}

Thumb::Thumb(Thumb const& t) : Finger(t.sensor.getPin(), t.pos_min, t.pos_max, t.motor_inverted) {
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

void Thumb::moveUp() {
	updatePos();
	motor.setPosition(pos);
}

const uint8_t  Thumb::sensor_pin = 1;
const uint16_t Thumb::thumb_pos_min = 500;
const uint16_t Thumb::thumb_pos_max = 2500;
const bool	   Thumb::inverted = true;
