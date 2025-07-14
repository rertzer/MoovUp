#include "MotorCheck.hpp"
#include "Uart.hpp"

extern Uart uart;

MotorCheck::MotorCheck(Arm& a) : arm(a) {}

void MotorCheck::run() {
	reset();
	jointTest("thumb", &arm.thumb);
	jointTest("index", &arm.index);
	jointTest("middle", &arm.middle);
	jointTest("ring", &arm.ring);
	jointTest("pinky", &arm.pinky);
	jointTest("wrist", &arm.wrist);
	jointTest("elbow", &arm.elbow);
	jointTest("shoulder", &arm.shoulder);
	reset();
}

void MotorCheck::reset() {
	uart.printstrnl("resetting...");
	arm.reset();
	arm.moveTrough();
}

void MotorCheck::jointTest(char const* name, Joint* joint) {
	uart.printstr(name);
	uart.printstr(" close up to ");
	uart.printNbr(joint->getMax());
	joint->setTarget(joint->getMax());
	arm.moveTrough();
	uart.printstr(" open up to ");
	uart.printNbr(joint->getMin());
	uart.printstrnl("");
	joint->setTarget(joint->getMin());
	arm.moveTrough();
}
