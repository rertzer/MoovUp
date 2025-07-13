#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define MOTOR_PWM_TOP 20000	 // 50 Hz

class Motor {
   public:
	Motor();
	Motor(Motor const& m);
	~Motor();
	Motor& operator=(Motor const& m);

	virtual uint16_t getPosition() const = 0;
	virtual void	 setPosition(uint16_t pos) = 0;

	static void			  MotorsInit();
	static const uint16_t motor_min_pwm;
	static const uint16_t motor_max_pwm;

   private:
};

#endif
