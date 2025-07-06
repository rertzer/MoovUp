#ifndef THUMB_HPP
#define THUMB_HPP

#include "Finger.hpp"
#include "MotorThumb.hpp"

class Thumb : public Finger {
   public:
	Thumb();
	Thumb(Thumb const& m);
	~Thumb();
	Thumb& operator=(Thumb const& m);

	uint16_t degre2pos(uint16_t deg);
	uint16_t pos2degre(uint16_t pos);
	void	 moveUp();

   private:
	MotorThumb			  motor;
	static const uint8_t  sensor_pin;
	static const uint16_t thumb_pos_min;
	static const uint16_t thumb_pos_max;
};

#endif
