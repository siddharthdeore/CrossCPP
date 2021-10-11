#include "SingleGimbalVSCMG.hpp"  
#include "rotations.hpp"
	
SingleGimbalVSCMG::SingleGimbalVSCMG()
{
	std::cout << "Single Gimmbal Control Moment Gyroscope" << std::endl;
}
	
SingleGimbalVSCMG::~SingleGimbalVSCMG()
{
	
}
void SingleGimbalVSCMG::rotateGimbal(double ag)
{
    this->setOrientation(Rotations::rotateY(ag) * this->getOrientation());
}
void SingleGimbalVSCMG::setGimbalVelocity(double wg)
{
    setVelocity(0,wg,0);
}