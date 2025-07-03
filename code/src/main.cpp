#include <util/delay.h>
#include "Index.hpp"
#include "Middle.hpp"
#include "Motor.hpp"
#include "MotorIndex.hpp"
#include "MotorMiddle.hpp"
#include "MotorPinky.hpp"
#include "MotorRing.hpp"
#include "MotorShoulder.hpp"
#include "MotorThumb.hpp"
#include "MotorWrist.hpp"
#include "Pinky.hpp"
#include "Ring.hpp"
#include "Shoulder.hpp"
#include "Uart.hpp"
#include "Wrist.hpp"
int main() {
	Uart uart;
	uart.init();
	bool direction = 1;

	Motor::MotorsInit();
	Index	 index;
	Middle	 middle;
	Ring	 ring;
	Pinky	 pinky;
	Shoulder shoulder;
	Wrist	 wrist;
	shoulder.setSpeed(8);
	index.setSpeed(10);
	middle.setSpeed(10);
	ring.setSpeed(10);
	pinky.setSpeed(12);
	wrist.setSpeed(10);

	uint16_t pos = 0;  // 1000;

	_delay_ms(1000);

	index.setTarget(180);
	middle.setTarget(0);
	ring.setTarget(0);
	pinky.setTarget(0);
	wrist.setTarget(0);
	shoulder.setTarget(150);

	while (42) {
		uart.printstr("run... ");
		uart.printNbr(pos);
		uart.printstrnl("");
		// index.setTarget(pos);
		// middle.setTar5et(pos);
		// ring.setTarget(pos);
		// pinky.setTarget(pos);
		// shoulder.setTarget(pos);
		// wrist.setTarget(pos);
		index.moveUp();
		middle.moveUp();
		ring.moveUp();
		pinky.moveUp();
		shoulder.moveUp();
		wrist.moveUp();
		if (direction) {
			pos++;
			if (pos > 180) {
				direction = 0;
				pos = 180;
			}

		} else {
			pos--;
			if (pos == 0) {
				direction = 1;
				pos = 0;
			}
		}

		_delay_ms(60);
	}
	return (0);
};
