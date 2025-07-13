#include "Shoulder.hpp"

Shoulder::Shoulder() : Joint(motor_default), motor(motor_default.start) {
	setTarget(150);
}

Shoulder::Shoulder(Shoulder const& s) : Joint(s.motor_setup), motor(s.motor) {
	*this = s;
}

Shoulder::~Shoulder() {}

Shoulder& Shoulder::operator=(Shoulder const& s) {
	if (this != &s) {
		Joint::operator=(s);
		motor = s.motor;
	}
	return (*this);
}

void Shoulder::move() {
	updatePos();
	motor.setPosition(pos);
}

void Shoulder::reset() {
	motor_setup = motor_default;
	target = motor_default.start;
}

const Joint::motor_setup_t Shoulder::motor_default = {Motor::motor_min_pwm, 1600, 1472, false};
