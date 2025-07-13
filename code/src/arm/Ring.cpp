#include "Ring.hpp"

Ring::Ring() : Finger(sensor_pin, motor_default), motor(motor_default.start) {}

Ring::Ring(Ring const& r) : Finger(r.sensor.getPin(), r.motor_setup), motor(r.motor) {
	*this = r;
}

Ring::~Ring() {}

Ring& Ring::operator=(Ring const& r) {
	if (this != &r) {
		Finger::operator=(r);
		motor = r.motor;
	}
	return (*this);
}

void Ring::moveUp() {
	updatePos();
	motor.setPosition(pos);
}

const uint8_t			   Ring::sensor_pin = 4;
const Joint::motor_setup_t Ring::motor_default = {Motor::motor_min_pwm, Motor::motor_max_pwm, Motor::motor_min_pwm,
												  false};
