#include "SensorCalibrate.hpp"
#include "Uart.hpp"

extern Uart uart;

SensorCalibrate::SensorCalibrate(Arm& a) : arm(a) {
	for (int i = 0; i < 5; ++i) {
		min[i] = SENSOR_MAX;
		max[i] = 0;
	}
}

uint8_t SensorCalibrate::calibrate() {
	uint8_t error = 0;
	for (int i = 0; i < 100; ++i) {
		setMinMax(&arm.thumb, 0);
		setMinMax(&arm.index, 1);
		setMinMax(&arm.middle, 2);
		setMinMax(&arm.ring, 3);
		setMinMax(&arm.pinky, 4);
		_delay_ms(40);
	}
	error += calibrateFinger(&arm.thumb, 0);
	error += calibrateFinger(&arm.index, 1);
	error += calibrateFinger(&arm.middle, 2);
	error += calibrateFinger(&arm.ring, 3);
	error += calibrateFinger(&arm.pinky, 4);

	return (error);
}

uint8_t SensorCalibrate::calibrateFinger(Finger* f, uint8_t idx) {
	if ((max[idx] - min[idx] > 2) || (min[idx] < 300) || (max[idx] > 600)) {
		uart.printstr("calibrate error finger ");
		uart.printNbr(idx);
		uart.printstr(" min: ");
		uart.printNbr(min[idx]);
		uart.printstr(" max: ");
		uart.printNbr(max[idx]);
		uart.printstrnl("");
		return (idx);
	}

	f->setPressureBase(max[idx]);
	uart.printstr("calibrate finger ");
	uart.printNbr(idx);
	uart.printstr(" at: ");
	uart.printNbr(max[idx]);
	uart.printstrnl("");

	return (0);
}

void SensorCalibrate::setMinMax(Finger* f, uint8_t idx) {
	uint16_t value = f->getPressure();
	if (value < min[idx]) {
		min[idx] = value;
	}
	if (value > max[idx]) {
		max[idx] = value;
	}
}
