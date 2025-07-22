#ifndef JOINT_HPP
#define JOINT_HPP

#include <stdint.h>

class Joint {
   public:
	typedef struct motor_setup_s {
		uint16_t min;
		uint16_t max;
		uint16_t start;
		bool	 inverted;
	} motor_setup_t;

	Joint(motor_setup_t ms);
	Joint(Joint const& m);
	~Joint();
	Joint& operator=(Joint const& m);

	uint16_t	 getMin() const;
	uint16_t	 getMax() const;
	uint16_t	 getPosition() const;
	uint16_t	 getTarget() const;
	void		 setTarget(uint16_t t);
	uint16_t	 getSpeed() const;
	void		 setSpeed(uint16_t s);
	virtual void move() = 0;

   protected:
	uint16_t degre2pos(uint16_t deg) const;
	uint16_t pos2degre(uint16_t pos) const;
	void	 updatePos();

	motor_setup_t motor_setup;
	uint16_t	  pos;
	uint16_t	  target;
	uint16_t	  speed;

	static constexpr uint16_t pwm_min{544};
	static constexpr uint16_t pwm_max{2400};
};

#endif
