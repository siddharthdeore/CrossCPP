#include "MomentumExchangeDevice.hpp"  
	
MomentumExchangeDevice::MomentumExchangeDevice()
{
    _axes << 1,0,0;
    _inertia << 1,1,1;
    _momentum << 0,0,0;
}
	
MomentumExchangeDevice::~MomentumExchangeDevice()
{
	
}

void MomentumExchangeDevice::setOrientation(Eigen::Vector3d axes)
{
    _axes = axes;
}
void MomentumExchangeDevice::setInertia(Eigen::Vector3d inertia)
{
    _inertia = inertia;
}
void MomentumExchangeDevice::setVelocity(Eigen::Vector3d vel)
{
    _omega = vel;
}
void MomentumExchangeDevice::setVelocity(double ws, double wg, double wt)
{
    _omega << ws,wg,wt;
}
void MomentumExchangeDevice::setOrientationGimbalSkew(double delta,double beta)
{
    Eigen::Vector3d vec;
    vec << 1,0,0;
    vec = Rotations::rotateZ(delta) * vec;
    setOrientation(Rotations::rotateY(beta) * vec);
}
Eigen::Vector3d MomentumExchangeDevice::getOrientation()
{
    return _axes;
}
Eigen::Vector3d MomentumExchangeDevice::getInertia()
{
    return _inertia;
}
Eigen::Vector3d MomentumExchangeDevice::getVelocity()
{
    return _omega;
}
Eigen::Vector3d MomentumExchangeDevice::calcMomentum()
{   
    // H = I * omega
    // could have used inertia as matrix instead of vector, hopefully this is faster
    _momentum << _inertia[0]*_omega[0],_inertia[1]*_omega[1],_inertia[2]*_omega[2];
    return _momentum;
}