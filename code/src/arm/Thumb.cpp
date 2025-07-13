#include "Thumb.hpp"

Thumb::Thumb() : Finger(sensor_pin, motor_default), motor(motor_default.start) {}

Thumb::Thumb(Thumb const& t) : Finger(t.sensor.getPin(), t.motor_default), motor(t.motor) {
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

const uint8_t			   Thumb::sensor_pin = 1;
const Joint::motor_setup_t Thumb::motor_default = {Motor::motor_min_pwm, Motor::motor_max_pwm, Motor::motor_max_pwm,
												   true};
