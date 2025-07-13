#include "Index.hpp"
#include "Finger.hpp"

Index::Index() : Finger(sensor_pin, motor_default), motor(motor_default.start) {}

Index::Index(Index const& i) : Finger(i.sensor.getPin(), i.motor_setup), motor(i.motor) {
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

void Index::move() {
	updatePos();
	motor.setPosition(pos);
}

void Index::reset() {
	motor_setup = motor_default;
	target = motor_default.start;
	mode = MoveMode::POSITION;
}

const uint8_t			   Index::sensor_pin = 2;
const Joint::motor_setup_t Index::motor_default = {Motor::motor_min_pwm, Motor::motor_max_pwm, Motor::motor_max_pwm,
												   true};
