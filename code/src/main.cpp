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
	// MotorShoulder shoulder;
	// MotorWrist	  wrist;
	// MotorMiddle	  middle;
	// MotorPinky	  pinky;
	// MotorRing	  ring;
	// MotorThumb	  thumb;
	// MotorIndex	  index;
	uint16_t pos = 0;  // 1000;

	_delay_ms(1000);

	index.setTarget(60);
	middle.setTarget(120);
	ring.setTarget(120);
	pinky.setTarget(140);
	wrist.setTarget(0);
	shoulder.setTarget(0);

	while (42) {
		uart.printstrnl("run...");
		// index.setTarget(pos);
		// middle.setTarget(pos);
		// ring.setTarget(pos);
		// pinky.setTarget(pos);
		shoulder.setTarget(pos);
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

		uart.printNbr(index.getTarget());
		uart.printstrnl("");

		_delay_ms(60);
	}
	return (0);
}
