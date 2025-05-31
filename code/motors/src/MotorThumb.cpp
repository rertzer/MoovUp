#include "MotorThumb.hpp"

/* For Arduino Mega, ATmega2560
 * using timer OC3B and pin D2 (PE4)
 */

MotorThumb::MotorThumb() {
	// connected, non-inverted
	TCCR3A |= (1 << COM3B1);
	TCCR3A &= ~(1 << COM3B0);

	// initial position at 0 degre (1 ms pulse)
	OCR3B = 1000;

	// set pin as output
	DDRE |= (1 << PE4);
}

MotorThumb::MotorThumb(MotorThumb const& m) {
	MotorThumb();
}

MotorThumb::~MotorThumb() {
	// disconnect
	TCCR3A &= ~(1 << COM3B1);
	TCCR3A &= ~(1 << COM3B0);

	// unset pin
	DDRE &= ~(1 << PE4);
}

MotorThumb& MotorThumb::operator=(MotorThumb const& m) {
	return (*this);
}

uint16_t MotorThumb::getPosition() {
	return ((uint16_t)OCR3B);
}

void MotorThumb::setPosition(uint16_t pos) {
	OCR3B = pos;
}
