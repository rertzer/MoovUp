#include "Arm.hpp"

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
