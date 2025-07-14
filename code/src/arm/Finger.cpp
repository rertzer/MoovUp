#include "Finger.hpp"

Finger::Finger(uint8_t sensor_pin, motor_setup_t ms)
	: Joint(ms), sensor(sensor_pin), pressure_target(0), mode(MoveMode::POSITION) {}

Finger::Finger(Finger const& f) : Joint(f.motor_setup), sensor(f.sensor.getPin()) {
	*this = f;
}

Finger::~Finger() {}

Finger& Finger::operator=(Finger const& f) {
	if (this != &f) {
		Joint::operator=(f);
		sensor = f.sensor;
		pressure_target = f.pressure_target;
		mode = f.mode;
	}
	return (*this);
}

uint16_t Finger::getPressure() const {
	return (sensor.readValue());
}

PressureLevel Finger::getPressureLevel() const {
	PressureLevel pl = PressureLevel::BASE;
	uint16_t	  p = sensor.readValue();

	if (p < pressure_base) {
		p = pressure_base;
	}
	p -= pressure_base;
	if (p >= 10) {
		pl = PressureLevel::HIGH;
	} else if (p >= 5) {
		pl = PressureLevel::MILD;
	} else if (p >= 2) {
		pl = PressureLevel::LIGHT;
	}
	return (pl);
}

uint16_t Finger::getPressureBase() const {
	return (pressure_base);
}

void Finger::setPressureBase(uint16_t base) {
	pressure_base = base;
}

uint16_t Finger::getPressureTarget() const {
	return (pressure_target);
}

void Finger::setPressureTarget(uint16_t p) {
	pressure_target = p;
}

MoveMode Finger::getMode() const {
	return (mode);
}

void Finger::setMode(MoveMode m) {
	mode = m;
}
