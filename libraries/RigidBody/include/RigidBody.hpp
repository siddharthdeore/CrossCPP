#ifndef RIGIDBODY_H
#define RIGIDBODY_H
#ifdef _MSC_VER
	#pragma once
#endif


#include <Eigen/Dense>
using namespace Eigen;


#include <boost/array.hpp>

#include <boost/numeric/odeint.hpp>
using namespace boost::numeric::odeint;

/*
typedef struct state_type {
	Quaterniond q;
	Vector3d omega;
}state_type;
*/
typedef boost::array< double , 7 > state_type;
class RigidBody  
{
	private:
		// angular velocity (Body rate vector)
		Vector3d _omega;
		// attitude quaternion
		Quaterniond _q;
		// body inertia matrix
		Matrix3d _inertia;
		// body mass
		double _mass;
		double Iyy = 1.0;
		double Ixx = 1.0;
		double Izz = 1.0;


	public:

		RigidBody();
		RigidBody(Quaterniond,Vector3d);
		~RigidBody();

		void setInertia(Matrix3d);
		void setState(Quaterniond,Vector3d);
		Quaterniond getQuaternion();
		Vector3d getAngularVelocity();
		
		// template< class State , class Deriv >
		// void operator()( const State &x_ , Deriv &dxdt_ , double t ) const
		void operator()(const state_type& x, state_type& dxdt, const double t);


		// outstream operator for printing body parameters
		friend std::ostream& operator<<(std::ostream& output, const RigidBody& Body);

};

//ostream operator is friend class, thus declared outside scope of base
std::ostream& operator<<(std::ostream& output, const RigidBody& Body);

#endif