#include "RigidBody.hpp"  
#include "rotations.hpp"

#include <iostream>
using namespace std;	

// Rigid body constructor
RigidBody::RigidBody()
{
    _q.setIdentity();
    _inertia.setIdentity();
    _omega << 0.0,0.0,0.0;
    _mass=0;
	
}

// Rigid body constructor with initial states
RigidBody::RigidBody(Quaterniond q,Vector3d omega)
{
    _q = q;
    _inertia.setIdentity();
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
    Quaterniond q(x[0],x[1],x[2],x[3]);
    Vector3d w,dw;
    w << x[4], x[5], x[6];
    q = Rotations::velocity_quaternion(q,w);
    Matrix3d SKW(3,3);
    SKW = Rotations::getSkew(w);

    Vector3d H = this->_inertia*w;
    dw = -SKW*H;
    cout << H <<endl;

    dxdt[0] = q.x();
    dxdt[1] = q.y();
    dxdt[2] = q.z();
    dxdt[3] = q.w();
    
    dxdt[1] = dw[0];
    dxdt[2] = dw[1];
    dxdt[3] = dw[2];

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

