#include "Arm.hpp"
#include <string.h>
#include "Uart.hpp"

extern Uart uart;

void Arm::move() {
	elbow.move();
	index.move();
	middle.move();
	pinky.move();
	ring.move();
	shoulder.move();
	thumb.move();
	wrist.move();
}

void Arm::moveTrough() {
	for (int i = 0; i < 250; ++i) {
		move();
		_delay_ms(20);
	}
}

void Arm::setSpeed(uint16_t s) {
	elbow.setSpeed(s);
	index.setSpeed(s);
	middle.setSpeed(s);
	pinky.setSpeed(s);
	ring.setSpeed(s);
	shoulder.setSpeed(s);
	thumb.setSpeed(s);
	wrist.setSpeed(s);
}

void Arm::reset() {
	elbow.reset();
	index.reset();
	middle.reset();
	pinky.reset();
	ring.reset();
	shoulder.reset();
	thumb.reset();
	wrist.reset();
	setSpeed(12);
}

void Arm::exec(char* line) {
	if (strcmp("shoulder left", line) == 0) {
		shoulderLeft();
	} else if (strcmp("shoulder right", line) == 0) {
		shoulderRight();
	} else if (strcmp("shoulder left", line) == 0) {
		shoulderLeft();
	} else if (strcmp("wrist left", line) == 0) {
		wristLeft();
	} else if (strcmp("wrist right", line) == 0) {
		wristRight();
	} else if (strcmp("hand open", line) == 0) {
		handOpen();
	} else if (strcmp("hand close", line) == 0) {
		handClose();
	} else if (strcmp("hand grab", line) == 0) {
		handGrab();
	} else if (strcmp("finger open", line) == 0) {
		fingerOpen();
	} else if (strcmp("finger close", line) == 0) {
		fingerClose();
	} else if (strcmp("index open", line) == 0) {
		indexOpen();
	} else if (strcmp("index close", line) == 0) {
		indexClose();
	}
}
void Arm::shoulderLeft() {
	shoulder.setTarget(80);
	uart.printstrnl("sl");
}
void Arm::shoulderRight() {
	shoulder.setTarget(0);
}
void Arm::wristLeft() {
	wrist.setTarget(180);
}
void Arm::wristRight() {
	wrist.setTarget(000);
}
void Arm::handOpen() {
	index.setTarget(0);
	middle.setTarget(0);
	ring.setTarget(0);
	pinky.setTarget(0);
}
void Arm::handClose() {
	index.setTarget(180);
	middle.setTarget(180);
	ring.setTarget(180);
	pinky.setTarget(180);
}
void Arm::handGrab() {
	uart.printstrnl("hg");
}
void Arm::thumbOpen() {
	thumb.setTarget(0);
}

void Arm::thumbClose() {
	thumb.setTarget(180);
}

void Arm::indexOpen() {
	index.setTarget(0);
}
void Arm::indexClose() {
	index.setTarget(180);
}
void Arm::fingerOpen() {
	index.setTarget(0);
	middle.setTarget(0);
	ring.setTarget(0);
	pinky.setTarget(0);
}
void Arm::fingerClose() {
	index.setTarget(180);
	middle.setTarget(180);
	ring.setTarget(180);
	pinky.setTarget(0);
}
