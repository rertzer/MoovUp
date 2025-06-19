#include <util/delay.h>
#include "Motor.hpp"
#include "Uart.hpp"

int main() {
	Uart uart;

	while (42) {
		uart.printstrnl("hello\n");
		_delay_ms(1000);
	}

	return (0);
}
