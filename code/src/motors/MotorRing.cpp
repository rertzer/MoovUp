#include "MotorRing.hpp"

/* For Arduino Mega, ATmega2560
 * using timer OC4A and pin D6 (PH3)
 */

MotorRing::MotorRing() {
	// connected, non-inverted
	TCCR4A |= (1 << COM4A1);
	TCCR4A &= ~(1 << COM4A0);

	// initial position at 0 degre (1 ms pulse)
	OCR4A = 1000;

	// set pin as output
	DDRH |= (1 << PH3);
}

MotorRing::MotorRing(MotorRing const& m) {
	MotorRing();
}

MotorRing::~MotorRing() {
	// disconnect
	TCCR4A &= ~(1 << COM4A1);
	TCCR4A &= ~(1 << COM4A0);

	// unset pin
	DDRH &= ~(1 << PH3);
}

MotorRing& MotorRing::operator=(MotorRing const& m) {
	return (*this);
}

uint16_t MotorRing::getPosition() {
	return ((uint16_t)OCR4A);
}

void MotorRing::setPosition(uint16_t pos) {
	OCR4A = pos;
}
