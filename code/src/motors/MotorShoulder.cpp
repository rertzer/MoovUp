#include "MotorShoulder.hpp"

/* For Arduino Mega, ATmega2560
 * using timer OC1B and pin D12 (PB6)
 */

MotorShoulder::MotorShoulder() {
	// connected, non-inverted
	TCCR1A |= (1 << COM1B1);
	TCCR1A &= ~(1 << COM1B0);

	// initial position at 180 degre (2 ms pulse)
	OCR1B = 2000;

	// set pin as output
	DDRB |= (1 << PB6);
}

MotorShoulder::MotorShoulder(MotorShoulder const& m) {
	MotorShoulder();
}

MotorShoulder::~MotorShoulder() {
	// disconnect
	TCCR1A &= ~(1 << COM1B1);
	TCCR1A &= ~(1 << COM1B0);

	// unset pin
	DDRB &= ~(1 << PB6);
}

MotorShoulder& MotorShoulder::operator=(MotorShoulder const& m) {
	return (*this);
}

uint16_t MotorShoulder::getPosition() {
	return ((uint16_t)OCR1B);
}

void MotorShoulder::setPosition(uint16_t pos) {
	OCR1B = pos;
}
