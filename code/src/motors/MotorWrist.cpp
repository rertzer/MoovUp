#include "MotorWrist.hpp"

/* For Arduino Mega, ATmega2560
 * using timer OC4C and pin D8 (PH5)
 */

MotorWrist::MotorWrist(uint16_t start_pos) {
	// connected, non-inverted
	TCCR4A |= (1 << COM4C1);
	TCCR4A &= ~(1 << COM4C0);

	// initial position
	OCR4C = start_pos;

	// set pin as output
	DDRH |= (1 << PH5);
}

MotorWrist::MotorWrist(MotorWrist const& m) : Motor() {
	(void)m;
}

MotorWrist::~MotorWrist() {
	// disconnect
	TCCR4A &= ~(1 << COM4C1);
	TCCR4A &= ~(1 << COM4C0);

	// unset pin
	DDRE &= ~(1 << PH5);
}

MotorWrist& MotorWrist::operator=(MotorWrist const& m) {
	(void)m;
	return (*this);
}

uint16_t MotorWrist::getPosition() const {
	return ((uint16_t)OCR4C);
}

void MotorWrist::setPosition(uint16_t pos) {
	OCR4C = pos;
}
