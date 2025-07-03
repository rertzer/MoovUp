#ifndef JOINT_HPP
#define JOINT_HPP

#include <stdint.h>

class Joint {
   public:
	Joint(uint16_t pos_min, uint16_t pos_max);
	Joint(Joint const& m);
	~Joint();
	Joint& operator=(Joint const& m);

	uint16_t	 getPosition();
	uint16_t	 getTarget();
	void		 setTarget(uint16_t t);
	uint16_t	 getSpeed();
	void		 setSpeed(uint16_t s);
	virtual void moveUp() = 0;

   protected:
	uint16_t degre2pos(uint16_t deg);
	uint16_t pos2degre(uint16_t pos);
	void	 updatePos();
	uint16_t pos_min;
	uint16_t pos_max;
	uint16_t pos;
	uint16_t target;
	uint16_t speed;
};

#endif
