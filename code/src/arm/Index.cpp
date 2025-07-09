#include "Index.hpp"
#include "Finger.hpp"

Index::Index() : Finger(sensor_pin, index_pos_min, index_pos_max, inverted), motor() {}

Index::Index(Index const& i) : Finger(i.sensor.getPin(), i.pos_min, i.pos_max, i.motor_inverted) {
	*this = i;
}

Index::~Index() {}

Index& Index::operator=(Index const& i) {
	if (this != &i) {
		Finger::operator=(i);
		motor = i.motor;
	}
	return (*this);
}

void Index::moveUp() {
	updatePos();
	motor.setPosition(pos);
}

const uint8_t  Index::sensor_pin = 2;
const uint16_t Index::index_pos_min = 500;
const uint16_t Index::index_pos_max = 2500;
const bool	   Index::inverted = true;
