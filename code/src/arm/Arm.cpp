#include "Arm.hpp"

void Arm::move() {
	elbow.moveUp();
	index.moveUp();
	middle.moveUp();
	pinky.moveUp();
	ring.moveUp();
	shoulder.moveUp();
	thumb.moveUp();
	wrist.moveUp();
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
