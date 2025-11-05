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

	Motor::MotorsInit();
	Arm arm;
	arm.reset();
	arm.moveTrough();
	_delay_ms(2000);

	MotorCheck motorcheck(arm);
	motorcheck.run();

	SensorCalibrate sensorcalibrate(arm);
	uint8_t			error = sensorcalibrate.calibrate();
	if (error) {
		uart.printstrnl("sensor calibration error...");
		_delay_ms(2000);
	}

	uart.printstr("MoovUp ready\r\n");
	while (true) {
		uart.printstr("Waiting for instructions...\r\n");
		uart.readline();
		uart.printline();

		arm.exec(uart.getline());
		arm.moveTrough();

		_delay_ms(60);
	}
	return (0);
};
