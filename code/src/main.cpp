#include <util/delay.h>

#include "Arm.hpp"
#include "Motor.hpp"
#include "MotorCheck.hpp"
#include "SensorCalibrate.hpp"
#include "Uart.hpp"

extern Uart uart;
Uart		uart;

int main() {
	uart.init();

	// bool		  direction = 1;
	// uint8_t		  moving = 0;
	// uint8_t const moving_top = 1;
	Motor::MotorsInit();
	Arm arm;
	arm.reset();
	arm.moveTrough();
	_delay_ms(2000);

	// MotorCheck motorcheck(arm);
	// motorcheck.run();
	//
	// SensorCalibrate sensorcalibrate(arm);
	// uint8_t			error = sensorcalibrate.calibrate();
	// if (error) {
	// 	uart.printstrnl("sensor calibration error...");
	// 	_delay_ms(2000);
	// }

	// uint16_t pos = 0;  // 1000;
	// uart.printstrnl("");
	// uart.printstr("index... ");
	while (true) {
		uart.printstr("MoovUp ready\r\nWaiting for instructions...\r\n");
		uart.readline();
		uart.printline();

		arm.exec(uart.getline());
		arm.moveTrough();

		// uart.printstr("thumb... ");
		// uart.printNbr(arm.thumb.getSensorValue());
		// uart.printstrnl("pos");
		// uart.printNbr(pos);
		// uart.printstr("index... ");
		// uart.printNbr(arm.index.getSensorValue());
		// uart.printstrnl("");
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
		// arm.index.setTarget(pos);
		// arm.middle.setTarget(pos);
		// arm.ring.setTarget(pos);
		// arm.pinky.setTarget(pos);
		// arm.shoulder.setTarget(pos);
		// arm.wrist.setTarget(pos);
		//
		//
		// arm.move();
		// if (direction) {
		// 	if (moving == moving_top) {
		// 		moving = 0;
		// 		pos++;
		// 	}
		// 	if (pos > 180) {
		// 		direction = 0;
		// 		pos = 180;
		// 	}
		//
		// } else {
		// 	if (moving == moving_top) {
		// 		moving = 0;
		// 		pos--;
		// 	}
		// 	if (pos == 0) {
		// 		direction = 1;
		// 		pos = 0;
		// 	}
		// }
		// moving++;
		_delay_ms(60);
	}
	return (0);
};
