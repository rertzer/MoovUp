#include <util/delay.h>
#include "motors_main.hpp"
#include "uart_init.h"
#include "uart_printstrnl.h"

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
}

void motors_run() {
	uart_printstrnl("running");
	_delay_ms(2000);
}
