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



using namespace std;
using namespace Eigen;
int main(){
    RigidBody body;

    cout << body.getQuaternion() << endl;
    cout << body.getAngularVelocity() << endl;
    cout << body;
    return 0;
}