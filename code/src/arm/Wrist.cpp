#include "Wrist.hpp"

Wrist::Wrist() : Joint(wrist_pos_min, wrist_pos_max), motor() {}

Wrist::Wrist(Wrist const& w) : Joint(w.pos_min, w.pos_max) {
	*this = w;
}

Wrist::~Wrist() {}

Wrist& Wrist::operator=(Wrist const& w) {
	if (this != &w) {
		Joint::operator=(w);
		motor = w.motor;
	}
	return (*this);
}

void Wrist::moveUp() {
	updatePos();
	motor.setPosition(pos);
}

const uint16_t Wrist::wrist_pos_min = 500;
const uint16_t Wrist::wrist_pos_max = 2500;
