#include "MotorElbow.hpp"

/* For Arduino Mega, ATmega2560
 * using timer OC1A and pin D11 (PB5)
 */

MotorElbow::MotorElbow() {
	// connected, non-inverted
	TCCR1A |= (1 << COM1A1);
	TCCR1A &= ~(1 << COM1A0);

	// initial position at 0 degre (1 ms pulse)
	OCR1A = 1000;

	// set pin as output
	DDRB |= (1 << PB5);
}

MotorElbow::MotorElbow(MotorElbow const& m) : Motor() {
	(void)m;
	MotorElbow();
}

MotorElbow::~MotorElbow() {
	// disconnect
	TCCR1A &= ~(1 << COM1A1);
	TCCR1A &= ~(1 << COM1A0);

	// unset pin
	DDRB &= ~(1 << PB5);
}

MotorElbow& MotorElbow::operator=(MotorElbow const& m) {
	(void)m;
	return (*this);
}

uint16_t MotorElbow::getPosition() const {
	return ((uint16_t)OCR1A);
}

void MotorElbow::setPosition(uint16_t pos) {
	OCR1A = pos;
}
