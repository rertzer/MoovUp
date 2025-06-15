#include "MotorPinky.hpp"

/* For Arduino Mega, ATmega2560
 * using timer OC4B and pin D7 (PH4)
 */

MotorPinky::MotorPinky() {
	// connected, non-inverted
	TCCR4A |= (1 << COM4B1);
	TCCR4A &= ~(1 << COM4B0);

	// initial position at 0 degre (1 ms pulse)
	OCR4B = 1000;

	// set pin as output
	DDRH |= (1 << PH4);
}

MotorPinky::MotorPinky(MotorPinky const& m) {
	MotorPinky();
}

MotorPinky::~MotorPinky() {
	// disconnect
	TCCR4A &= ~(1 << COM4B1);
	TCCR4A &= ~(1 << COM4B0);

	// unset pin
	DDRH &= ~(1 << PH4);
}

MotorPinky& MotorPinky::operator=(MotorPinky const& m) {
	return (*this);
}

uint16_t MotorPinky::getPosition() {
	return ((uint16_t)OCR4B);
}

void MotorPinky::setPosition(uint16_t pos) {
	OCR4B = pos;
}
