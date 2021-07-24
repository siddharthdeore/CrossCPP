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

using namespace std;
using namespace Eigen;
using namespace boost::numeric::odeint;
typedef runge_kutta_cash_karp54< state_type > error_stepper_type;
typedef controlled_runge_kutta< error_stepper_type > controlled_stepper_type;

int main() {
	RigidBody body;
	state_type X = { 1.0, 0.0, 0.0, 0.0, 0.01, 0.00, 0.0 };
	Quaterniond q(X[0], X[1], X[2], X[3]);
	Vector3d w(X[4], X[5], X[6]);
	runge_kutta4< state_type > rk4;
	//integrate_n_steps(rk4, body, X, 0.0, 0.0001, 10);s
	for(int i=0;i<100;i++){
	integrate_adaptive(make_controlled< error_stepper_type >(1.0e-6, 1.0e-6),
					   body, X, 0.0, 1.0, 0.001);
	for (auto it = std::begin(X); it != std::end(X); ++it)
	{
		std::cout << ' ' << *it;
	}
	std::cout << '\n';
	}
	int qq;
	std::cin>>qq;
    return 0;
}