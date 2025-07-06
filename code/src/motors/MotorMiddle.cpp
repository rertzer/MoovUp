#include "MotorMiddle.hpp"

/* For Arduino Mega, ATmega2560
 * using timer OC3A and pin D5 (PE3)
 */

MotorMiddle::MotorMiddle() {
	// connected, non-inverted
	TCCR3A |= (1 << COM3A1);
	TCCR3A &= ~(1 << COM3A0);

	// initial position at 0 degre (1 ms pulse)
	OCR3A = 1000;

	// set pin as output
	DDRE |= (1 << PE3);
}

MotorMiddle::MotorMiddle(MotorMiddle const& m) : Motor() {
	(void)m;
	MotorMiddle();
}

MotorMiddle::~MotorMiddle() {
	// disconnect
	TCCR3A &= ~(1 << COM3A1);
	TCCR3A &= ~(1 << COM3A0);

	// unset pin
	DDRE &= ~(1 << PE3);
}

MotorMiddle& MotorMiddle::operator=(MotorMiddle const& m) {
	(void)m;
	return (*this);
}

uint16_t MotorMiddle::getPosition() const {
	return ((uint16_t)OCR3A);
}

void MotorMiddle::setPosition(uint16_t pos) {
	OCR3A = pos;
}
