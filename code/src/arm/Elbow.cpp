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

void Elbow::moveUp() {
	updatePos();
	motor.setPosition(pos);
}

const Joint::motor_setup_t Elbow::motor_default = {Motor::motor_min_pwm, Motor::motor_max_pwm, Motor::motor_min_pwm,
												   false};
