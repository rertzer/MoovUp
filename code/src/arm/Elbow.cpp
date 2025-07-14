#include "Elbow.hpp"

Elbow::Elbow() : Joint(motor_default), motor(motor_default.start) {}

Elbow::Elbow(Elbow const& e) : Joint(e.motor_setup), motor(e.motor) {
	*this = e;
}

Elbow::~Elbow() {}

Elbow& Elbow::operator=(Elbow const& e) {
	if (this != &e) {
		Joint::operator=(e);
		motor = e.motor;
	}
	return (*this);
}

void Elbow::move() {
	updatePos();
	motor.setPosition(pos);
}

void Elbow::reset() {
	motor_setup = motor_default;
	target = motor_default.start;
}

const Joint::motor_setup_t Elbow::motor_default = {Joint::pwm_min, Joint::pwm_max, Joint::pwm_min, false};
