#include "Pinky.hpp"
#include "Finger.hpp"

Pinky::Pinky() : Finger(sensor_pin, motor_default), motor(motor_default.start) {}

Pinky::Pinky(Pinky const& p) : Finger(p.sensor.getPin(), p.motor_setup), motor(p.motor) {
	*this = p;
}

Pinky::~Pinky() {}

Pinky& Pinky::operator=(Pinky const& p) {
	if (this != &p) {
		Finger::operator=(p);
		motor = p.motor;
	}
	return (*this);
}

void Pinky::move() {
	updatePos();
	motor.setPosition(pos);
}

void Pinky::reset() {
	motor_setup = motor_default;
	target = motor_default.start;
	mode = MoveMode::POSITION;
}

const uint8_t			   Pinky::sensor_pin = 5;
const Joint::motor_setup_t Pinky::motor_default = {Motor::motor_min_pwm, Motor::motor_max_pwm, Motor::motor_min_pwm,
												   false};
