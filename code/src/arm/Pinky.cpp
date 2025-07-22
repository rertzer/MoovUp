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

constexpr uint8_t			   Pinky::sensor_pin;
constexpr Joint::motor_setup_t Pinky::motor_default;
