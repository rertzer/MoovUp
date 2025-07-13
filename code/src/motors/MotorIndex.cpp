#include "MotorIndex.hpp"
#include "Uart.hpp"

extern Uart uart;

/* For Arduino Mega, ATmega2560
 * using timer OC3C and pin D3 (PE5)
 */

MotorIndex::MotorIndex(uint16_t start_pos) {
	// connected, non-inverted
	TCCR3A |= (1 << COM3C1);
	TCCR3A &= ~(1 << COM3C0);

	// initial position
	OCR3C = start_pos;

	// set pin
	DDRE |= (1 << PE5);
}

MotorIndex::MotorIndex(MotorIndex const& m) : Motor() {
	(void)m;
}

MotorIndex::~MotorIndex() {
	// disconnect
	TCCR3A &= ~(1 << COM3C1);
	TCCR3A &= ~(1 << COM3C0);

	// unset pin
	DDRE &= ~(1 << PE5);
}

MotorIndex& MotorIndex::operator=(MotorIndex const& m) {
	(void)m;
	return (*this);
}

uint16_t MotorIndex::getPosition() const {
	return ((uint16_t)OCR3C);
}

void MotorIndex::setPosition(uint16_t pos) {
	OCR3C = pos;
}
