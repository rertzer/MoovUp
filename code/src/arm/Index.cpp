#include "Index.hpp"
#include "Finger.hpp"

Index::Index() : Finger(2, 500, 2500), motor() {}

Index::Index(Index const& i) : Finger(i.sensor.getPin(), 500, 2500) {
	*this = i;
}

Index::~Index() {}

Index& Index::operator=(Index const& i) {
	if (this != &i) {
		pos = i.pos;
		target = i.target;
		speed = i.speed;
		mode = i.mode;
	}
	return (*this);
}

void Index::moveUp() {
	updatePos();
	motor.setPosition(pos);
}
