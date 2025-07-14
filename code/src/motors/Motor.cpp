#include "Motor.hpp"
#include <avr/io.h>

extern "C" void __cxa_pure_virtual() {
	while (42)
		;
}

Motor::Motor() {}
Motor::Motor(Motor const& m) {
	(void)m;
}
Motor::~Motor() {}

Motor& Motor::operator=(Motor const& m) {
	(void)m;
	return (*this);
}

void Motor::MotorsInit() {
	// For Arduino Mega (ATmel2560)
	// mode 10 for timers 1,3 and 4
	TCCR1A |= 1 << WGM11;
	TCCR1A &= ~(1 << WGM00);
	TCCR1B |= 1 << WGM13;
	TCCR1B &= ~(1 << WGM12);

	TCCR3A |= 1 << WGM31;
	TCCR3A &= ~(1 << WGM30);
	TCCR3B |= 1 << WGM13;
	TCCR3B &= ~(1 << WGM12);

	TCCR4A |= 1 << WGM41;
	TCCR4A &= ~(1 << WGM40);
	TCCR4B |= 1 << WGM13;
	TCCR4B &= ~(1 << WGM12);

	// prescaler 8 ( 2MHz) for timers 1, 3 and 4
	TCCR1B |= 1 << CS11;
	TCCR1B &= ~((1 << CS12) | (1 << CS10));

	TCCR3B |= 1 << CS31;
	TCCR3B &= ~((1 << CS32) | (1 << CS30));

	TCCR4B |= 1 << CS41;
	TCCR4B &= ~((1 << CS42) | (1 << CS40));

	TCCR1C = 0;
	TCCR3C = 0;
	TCCR4C = 0;

	// PWM frequency
	ICR1 = MOTOR_PWM_TOP;
	ICR3 = MOTOR_PWM_TOP;
	ICR4 = MOTOR_PWM_TOP;
}
