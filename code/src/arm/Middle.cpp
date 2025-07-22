#include "Middle.hpp"
#include "Finger.hpp"

Middle::Middle() : Finger(sensor_pin, motor_default), motor(motor_default.start) {}

Middle::Middle(Middle const& m) : Finger(m.sensor.getPin(), m.motor_setup), motor(m.motor) {
	*this = m;
}

Middle::~Middle() {}

Middle& Middle::operator=(Middle const& m) {
	if (this != &m) {
		Finger::operator=(m);
		motor = m.motor;
	}
	return (*this);
}

void Middle::move() {
	updatePos();
	motor.setPosition(pos);
}

void Middle::reset() {
	motor_setup = motor_default;
	target = motor_default.start;
	mode = MoveMode::POSITION;
}

constexpr uint8_t			   Middle::sensor_pin;
constexpr Joint::motor_setup_t Middle::motor_default;
