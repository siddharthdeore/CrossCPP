/**
 * @file demo.cpp
 *
 * @brief rotation in euclidian space demonstrations
 *
 * @author Siddharth Deore
 * Contact: siddharth.deore@iit.it
 *
 */
#include "rotations.hpp"
#include <Eigen/Dense>

#include <iostream>

using namespace std;
using namespace Eigen;
int main(){
    Matrix3d M;
    Vector3d vec(1.0,2.0,3.0);
    cout << endl;
    cout << "Rotate Vector" << endl;

    M = Rotations::rotateX(1.570796 /3 ) * Rotations::rotateY(1.570796 /2) * Rotations::rotateZ(1.570796);
    cout << "Get Skew matrix of vector (1 2 3)" << endl;
    cout << M*vec << endl;
    cout << endl;
    cout << Rotations::getSkew(vec);

    Quaterniond q(1,0,0,0);
    Quaterniond qd(0,0,1,0);
    
    cout << endl;
    cout << Rotations::error_quaternion(q,qd) <<endl;
    cout << endl;

    cout << endl;
    cout << Rotations::velocity_quaternion(q,vec) <<endl;
    cout << endl;

    
    //cout << Rotations::getSkew(vec);

    cout << endl;
    return 0;
}