#include <util/delay.h>

#include "Arm.hpp"
#include "Motor.hpp"
#include "Uart.hpp"

extern Uart uart;
Uart		uart;

int main() {
	uart.init();

	bool		  direction = 1;
	uint8_t		  moving = 0;
	uint8_t const moving_top = 1;
	Motor::MotorsInit();
	Arm arm;
	arm.setSpeed(12);

	uint16_t pos = 0;  // 1000;

	// for (int i = 0; i < 250; ++i) {
	// 	arm.move();
	// 	_delay_ms(20);
	// }

	_delay_ms(2000);

	// uart.printstrnl("");
	// uart.printstr("index... ");
	while (false) {
		// uart.printstr("thumb... ");
		// uart.printNbr(arm.thumb.getSensorValue());
		uart.printstrnl("pos");
		uart.printNbr(pos);
		// uart.printstr("index... ");
		// uart.printNbr(arm.index.getSensorValue());
		uart.printstrnl("");
		// uart.printstr("     middle... ");
		// uart.printNbr(arm.middle.getSensorValue());
		// uart.printstrnl("");
		// uart.printstr("ring... ");
		// uart.printNbr(arm.ring.getSensorValue());
		// uart.printstrnl("");
		// uart.printstr("pinky... ");
		// uart.printNbr(arm.pinky.getSensorValue());
		// uart.printstrnl("");
		// arm.thumb.setTarget(pos);
		arm.index.setTarget(pos);
		// arm.middle.setTarget(pos);
		// arm.ring.setTarget(pos);
		// arm.pinky.setTarget(pos);
		// arm.shoulder.setTarget(pos);
		// arm.wrist.setTarget(pos);
		arm.move();
		if (direction) {
			if (moving == moving_top) {
				moving = 0;
				pos++;
			}
			if (pos > 180) {
				direction = 0;
				pos = 180;
			}

		} else {
			if (moving == moving_top) {
				moving = 0;
				pos--;
			}
			if (pos == 0) {
				direction = 1;
				pos = 0;
			}
		}
		moving++;
		_delay_ms(60);
	}
	return (0);
};
