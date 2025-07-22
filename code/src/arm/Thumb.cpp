#include "Thumb.hpp"
#include "Finger.hpp"

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

void Thumb::move() {
	updatePos();
	motor.setPosition(pos);
}

void Thumb::reset() {
	motor_setup = motor_default;
	target = motor_default.start;
	mode = MoveMode::POSITION;
}
constexpr uint8_t			   Thumb::sensor_pin;
constexpr Joint::motor_setup_t Thumb::motor_default;
