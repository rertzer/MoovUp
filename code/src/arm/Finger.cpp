#include "Finger.hpp"
#include "arm.hpp"

Finger::Finger(uint8_t sensor_pin, uint16_t p_min, uint16_t p_max)
	: Joint(p_min, p_max), sensor(sensor_pin), pressure_target(0), mode(MoveMode::POSITION) {}

Finger::Finger(Finger const& f) : Joint(f.pos_min, f.pos_max), sensor(f.sensor.getPin()) {
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

uint16_t Finger::getPressureTarget() {
	return (pressure_target);
}

void Finger::setPressureTarget(uint16_t p) {
	pressure_target = p;
}

MoveMode Finger::getMode() {
	return (mode);
}

void Finger::setMode(MoveMode m) {
	mode = m;
}
