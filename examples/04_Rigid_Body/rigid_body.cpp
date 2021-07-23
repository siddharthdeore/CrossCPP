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
int main(){
    RigidBody body;
    state_type X = {1,0,0,0.0,0.01,0.02,0.01};
    runge_kutta4< state_type > rk4;
    const double dt = 0.01;
    integrate_n_steps(rk4, body,X,0.0,dt,1000);
    Quaterniond q(X[0],X[1],X[2],X[3]);
    cout << q <<endl;
    Vector3d w;
    w << X[4],X[5],X[6];
    body.setState(q,w);
    cout << body.getQuaternion() << endl;
    cout << body.getAngularVelocity() << endl;
    return 0;
}