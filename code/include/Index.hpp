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
	MotorIndex motor;
};

#endif
