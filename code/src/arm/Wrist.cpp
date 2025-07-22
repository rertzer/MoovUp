#include "Wrist.hpp"

Wrist::Wrist() : Joint(motor_default), motor(motor_default.start) {}

Wrist::Wrist(Wrist const& w) : Joint(w.motor_default), motor(w.motor) {
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

void Wrist::move() {
	updatePos();
	motor.setPosition(pos);
}

void Wrist::reset() {
	motor_setup = motor_default;
	target = motor_default.start;
}
constexpr Joint::motor_setup_t Wrist::motor_default;
