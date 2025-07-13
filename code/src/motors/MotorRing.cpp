#include "MotorRing.hpp"

/* For Arduino Mega, ATmega2560
 * using timer OC4A and pin D6 (PH3)
 */

MotorRing::MotorRing(uint16_t start_pos) {
	// connected, non-inverted
	TCCR4A |= (1 << COM4A1);
	TCCR4A &= ~(1 << COM4A0);

	// initial position
	OCR4A = start_pos;

	// set pin as output
	DDRH |= (1 << PH3);
}

MotorRing::MotorRing(MotorRing const& m) : Motor() {
	(void)m;
}

MotorRing::~MotorRing() {
	// disconnect
	TCCR4A &= ~(1 << COM4A1);
	TCCR4A &= ~(1 << COM4A0);

	// unset pin
	DDRH &= ~(1 << PH3);
}

MotorRing& MotorRing::operator=(MotorRing const& m) {
	(void)m;
	return (*this);
}

uint16_t MotorRing::getPosition() const {
	return ((uint16_t)OCR4A);
}

void MotorRing::setPosition(uint16_t pos) {
	OCR4A = pos;
}
