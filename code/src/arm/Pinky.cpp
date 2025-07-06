#include "Pinky.hpp"

Pinky::Pinky() : Finger(sensor_pin, pinky_pos_min, pinky_pos_max), motor() {}

Pinky::Pinky(Pinky const& p) : Finger(p.sensor.getPin(), p.pos_min, p.pos_max) {
	*this = p;
}

Pinky::~Pinky() {}

Pinky& Pinky::operator=(Pinky const& p) {
	if (this != &p) {
		Finger::operator=(p);
		motor = p.motor;
	}
	return (*this);
}

void Pinky::moveUp() {
	updatePos();
	motor.setPosition(pos);
}

const uint8_t  Pinky::sensor_pin = 5;
const uint16_t Pinky::pinky_pos_min = 500;
const uint16_t Pinky::pinky_pos_max = 2500;
