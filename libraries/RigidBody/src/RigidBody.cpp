#include "RigidBody.hpp"  
#include "rotations.hpp"

#include <iostream>
using namespace std;	

// Rigid body constructor
RigidBody::RigidBody()
{
    _q.setIdentity();
    _inertia << 1.0, 0.0, 0.0,
                0.0, 1.0, 0.0,
                0.0, 0.0, 1.0;

    _omega << 0.0, 0.0, 0.0;
    _mass=0;
	
}

// Rigid body constructor with initial states
RigidBody::RigidBody(Quaterniond q,Vector3d omega)
{
    _q = q;
    _inertia << 1.0, 0.0, 0.0,
                0.0, 1.0, 0.0,
                0.0, 0.0, 1.0;
    _mass=0;
    _omega = omega;
	
}
	
RigidBody::~RigidBody()
{
	
}

void RigidBody::setInertia(Matrix3d inertia)
{
    _inertia = inertia;
}
void RigidBody::setState(Quaterniond q,Vector3d omega)
{
    _q=q;
    _omega=omega;
}
Quaterniond RigidBody::getQuaternion()
{
    return _q;
}
Vector3d RigidBody::getAngularVelocity()
{
    return _omega;
}

void RigidBody::operator()(const state_type& x, state_type& dxdt, const double t) {
    Quaterniond q(x[0], x[1], x[2], x[3]);
    q.normalize();
    Vector3d w(x[4],x[5],x[6]);
	// Quaternion Kinematics
	Quaterniond dq = Rotations::velocity_quaternion(q,w);
	// Angular momentum H = Jxw
    Vector3d H = this->_inertia*w;
	// Rigid Body Dymanics Jw_dot = w x (H)
	Vector3d dw = - (Rotations::getSkew(w)*H);
	dw = this->_inertia.inverse() * dw;

    dxdt[0] = dq.w();
    dxdt[1] = dq.x();
    dxdt[2] = dq.y();
    dxdt[3] = dq.z();
    
    dxdt[4] = dw[0];
    dxdt[5] = dw[1];
    dxdt[6] = dw[2];

    // kinematics
    //q = Rotations::velocity_quaternion(x.q,x.omega);
    // dynamics
    //Vector3d H = this->_inertia*x.omega;
    //dxdt.omega = -x.omega.cross(H);
}

std::ostream& operator<<(std::ostream& out, const RigidBody& Body) 
{
    out << "Inertia (kg m^2) : \n" << Body._inertia << std::endl;
    out << "Mass (kg) \t: " << Body._mass << std::endl;
    out << "Attitude quaternion \t: " << Body._q << std::endl;
    out << "Angular Velocity \t: " << Body._omega[0] << " "<< Body._omega[1] << " "<< Body._omega[2] << std::endl;
    return out;
}

