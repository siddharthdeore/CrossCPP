#ifndef MOMENTUMEXCHANGEDEVICE_H
#define MOMENTUMEXCHANGEDEVICE_H
#pragma once
	
#include <Eigen/Dense>
#include <rotations.hpp>
#include <iostream>
class MomentumExchangeDevice  
{
	private:
        // Inerita about Spin Axis, Gimbal axis, Transverse Axis
        Eigen::Vector3d _inertia;
        // Direction basis of Spin Axis, Gimbal axis, Transverse Axis with respect to body frame
        Eigen::Vector3d _axes;
        // Angular velocity about Spin Axis, Gimbal axis, Transverse Axis
        Eigen::Vector3d _omega;

        Eigen::Vector3d _momentum;
	public:

		MomentumExchangeDevice();
		~MomentumExchangeDevice();
        
        //! Axes orientation of Spin Axis, Gimbal axis, Transverse Axis
        void setOrientation(Eigen::Vector3d);
        void setInertia(Eigen::Vector3d);
        void setVelocity(Eigen::Vector3d);
        void setVelocity(double,double,double);
        void setOrientationGimbalSkew(double delta,double beta);
        Eigen::Vector3d getOrientation();
        Eigen::Vector3d getInertia();
        Eigen::Vector3d getVelocity();
        Eigen::Vector3d calcMomentum();
};
#endif