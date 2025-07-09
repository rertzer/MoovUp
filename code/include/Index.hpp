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

	void moveUp();

   private:
	MotorIndex			  motor;
	static const uint8_t  sensor_pin;
	static const uint16_t index_pos_min;
	static const uint16_t index_pos_max;
	static const bool	  inverted;
};

#endif
