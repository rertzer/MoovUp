#include "MotorWrist.hpp"

/* For Arduino Mega, ATmega2560
 * using timer OC4C and pin D8 (PH5)
 */

MotorWrist::MotorWrist() {
	// connected, non-inverted
	TCCR4A |= (1 << COM4C1);
	TCCR4A &= ~(1 << COM4C0);

	// initial position at 90 degre (1.5 ms pulse)
	OCR4C = 1500;

	// set pin as output
	DDRH |= (1 << PH5);
}

MotorWrist::MotorWrist(MotorWrist const& m) : Motor() {
	(void)m;
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
	(void)m;
	return (*this);
}

uint16_t MotorWrist::getPosition() const {
	return ((uint16_t)OCR4C);
}

void MotorWrist::setPosition(uint16_t pos) {
	OCR4C = pos;
}
