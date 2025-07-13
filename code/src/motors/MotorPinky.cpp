#include "MotorPinky.hpp"

/* For Arduino Mega, ATmega2560
 * using timer OC4B and pin D7 (PH4)
 */

MotorPinky::MotorPinky(uint16_t start_pos) {
	// connected, non-inverted
	TCCR4A |= (1 << COM4B1);
	TCCR4A &= ~(1 << COM4B0);

	// initial position
	OCR4B = start_pos;

	// set pin as output
	DDRH |= (1 << PH4);
}

MotorPinky::MotorPinky(MotorPinky const& m) : Motor() {
	(void)m;
}

MotorPinky::~MotorPinky() {
	// disconnect
	TCCR4A &= ~(1 << COM4B1);
	TCCR4A &= ~(1 << COM4B0);

	// unset pin
	DDRH &= ~(1 << PH4);
}

MotorPinky& MotorPinky::operator=(MotorPinky const& m) {
	(void)m;
	return (*this);
}

uint16_t MotorPinky::getPosition() const {
	return ((uint16_t)OCR4B);
}

void MotorPinky::setPosition(uint16_t pos) {
	OCR4B = pos;
}
