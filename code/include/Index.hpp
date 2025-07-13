#ifndef INDEX_HPP
#define INDEX_HPP

#include "Finger.hpp"
#include "MotorIndex.hpp"

class Index : public Finger {
   public:
	Index();
	Index(Index const& m);
	~Index();
	Index& operator=(Index const& m);

	void move();
	void reset();

   private:
	MotorIndex				   motor;
	static const uint8_t	   sensor_pin;
	static const motor_setup_t motor_default;
};

#endif
