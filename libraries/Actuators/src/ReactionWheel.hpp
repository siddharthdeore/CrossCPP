#ifndef REACTIONWHEEL_H
#define REACTIONWHEEL_H

#include "MomentumExchangeDevice.hpp"	
class ReactionWheel : public  MomentumExchangeDevice
{
	private:

	public:

		ReactionWheel();
		~ReactionWheel();
        void setSpinVelocity(double);

};
#endif