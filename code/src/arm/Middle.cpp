#include "Middle.hpp"

Middle::Middle() : Finger(sensor_pin, middle_pos_min, middle_pos_max), motor() {}

Middle::Middle(Middle const& m) : Finger(m.sensor.getPin(), m.pos_min, m.pos_max) {
	*this = m;
}

Middle::~Middle() {}

Middle& Middle::operator=(Middle const& m) {
	if (this != &m) {
		Finger::operator=(m);
		motor = m.motor;
	}
	return (*this);
}

void Middle::moveUp() {
	updatePos();
	motor.setPosition(pos);
}

const uint8_t  Middle::sensor_pin = 3;
const uint16_t Middle::middle_pos_min = 500;
const uint16_t Middle::middle_pos_max = 2500;
