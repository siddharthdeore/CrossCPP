#ifndef SINGLEGIMBALVSCMG_H
#define SINGLEGIMBALVSCMG_H

#include "ReactionWheel.hpp"	
class SingleGimbalVSCMG : public ReactionWheel
{
	private:

	public:

		SingleGimbalVSCMG();
		~SingleGimbalVSCMG();
        void setSpinVelocity(double);
        void setGimbalVelocity(double);
        void rotateGimbal(double);

};
#endif