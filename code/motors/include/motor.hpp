#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

class motor {
   public:
	motor();
	motor(motor const& m);
	virtual ~motor();
	motor& operator=(motor const& m);

	virtual uint16_t get_position() = 0;
	virtual void	 set_position(uint16_t pos) = 0;

   private:
};

#endif
