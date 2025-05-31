#include "MotorWrist.hpp"

/* For Arduino Mega, ATmega2560
 * using timer OC4C and pin D8 (PH5)
 */

MotorWrist::MotorWrist() {
	// connected, non-inverted
	TCCR4A |= (1 << COM4C1);
	TCCR4A &= ~(1 << COM4C0);

	// initial position at 0 degre (1 ms pulse)
	OCR4C = 1000;

	// set pin as output
	DDRE |= (1 << PH5);
}

MotorWrist::MotorWrist(MotorWrist const& m) {
	MotorWrist();
}

MotorWrist::~MotorWrist() {
	// disconnect
	TCCR4A &= ~(1 << COM4C1);
	TCCR4A &= ~(1 << COM4C0);

	// unset pin
	DDRE &= ~(1 << PH5);
}

MotorWrist& MotorWrist::operator=(MotorWrist const& m) {
	return (*this);
}

uint16_t MotorWrist::getPosition() {
	return ((uint16_t)OCR4C);
}

void MotorWrist::setPosition(uint16_t pos) {
	OCR4C = pos;
}
