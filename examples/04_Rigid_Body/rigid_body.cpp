/**
 * @file demo.cpp
 *
 * @brief rotation in euclidian space demonstrations
 *
 * @author Siddharth Deore
 * Contact: siddharth.deore@iit.it
 *
 */
#include <Eigen/Dense>
#include <iostream>

#include "rotations.hpp"
#include "RigidBody.hpp"


#include <boost/numeric/odeint.hpp>

using namespace Eigen;
using namespace boost::numeric::odeint;
typedef runge_kutta_cash_karp54< state_type > error_stepper_type;
typedef controlled_runge_kutta< error_stepper_type > controlled_stepper_type;

int main() {
	RigidBody body;

	Matrix3d I(3,3);
	I << 1,0,0,
		 0,2,0,
	     0,0,3;
	body.setInertia(I);
	body.setState(Quaterniond(1,0,0,0),Vector3d(0,0.02,0.01));
	auto q = body.getQuaternion();
	auto w = body.getAngularVelocity();
	state_type X = { q.w(), q.x(), q.y(), q.z(), w[0], w[1], w[2] };
	
	
	//runge_kutta4< state_type > rk4;
	//integrate_n_steps(rk4, body, X, 0.0, 0.0001, 10);
	std::cout<<std::fixed <<std::setprecision(4) <<std::setw(8);
	for(int i=0;i<100;i++){
		integrate_adaptive(make_controlled< error_stepper_type >(1.0e-6, 1.0e-6), body, X, 0.0, 1.0, 0.001);
		std::cout << "Time : " << i+1;

		for (auto it = std::begin(X); it != std::end(X); ++it)
		{
			std::cout << "\t" << *it;
		}
		std::cout << endl;
	}
	body.setState(Quaterniond(X[0], X[1], X[2], X[3]),Vector3d(X[4], X[5], X[6]));
    return 0;
}