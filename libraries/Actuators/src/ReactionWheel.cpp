#include "ReactionWheel.hpp"  
	
ReactionWheel::ReactionWheel()
{
	std::cout << "Reaction Wheel" << std::endl;
}
	
ReactionWheel::~ReactionWheel()
{
	
}

void ReactionWheel::setSpinVelocity(double omega_spin)
{
    setVelocity(omega_spin,0,0);
}