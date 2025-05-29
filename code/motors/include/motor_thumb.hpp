#ifndef MOTOR_THUMB_HPP
#define MOTOR_THUMB_HPP

#include "motor.hpp"

class motor_thumb : public motor {
   public:
	motor_thumb();
	motor_thumb(motor_thumb const& m);
	~motor_thumb();
	motor_thumb& operator=(motor_thumb const& m);

	uint16_t get_position();
	void	 set_position();

   private:
};

#endif
