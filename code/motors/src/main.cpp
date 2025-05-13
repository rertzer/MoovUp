#include <util/delay.h>
#include "motors_main.hpp"
#include "uart_init.h"
#include "uart_printstrnl.h"

int	 duty = 1;
bool ascending = true;

ISR(TIMER0_OVF_vect) {
	if (ascending) {
		if (duty >= 100) {
			duty = 99;
			ascending = false;
		} else
			++duty;
	} else {
		if (duty <= 0) {
			duty = 1;
			ascending = true;
		} else
			--duty;
	}
	OCR1A = duty;
}

int main() {
	motors_init();
	while (42) {
		motors_run();
	}
	uart_init();

	return (0);
}

void motors_init() {
	uart_init();

	/* set port D2 as output */
	DDRD |= (1 << DDD2);

	/*timer 0 settings mode 15*/
	TCCR0A = 0b11000011;
	TCCR0B = 0b00001101;
	OCR0A = 78;
	TIMSK0 = (1 << TOIE0);

	/* timer 1 settings mode 14*/
	TCCR1A = (1 << COM1A1) | (1 << WGM11);
	TCCR1B = 0b00011101;
	OCR1A = duty;
	ICR1 = TIMER1_TOP;

	sei();
}

void motors_run() {
	uart_printstrnl("running");
	_delay_ms(2000);
}
