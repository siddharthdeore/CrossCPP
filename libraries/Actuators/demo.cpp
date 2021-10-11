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
#include "VSCMG.hpp"



using namespace std;
using namespace Eigen;
int main(){
    VSCMG body;

    cout << body.getQuaternion() << endl;
    cout << body.getAngularVelocity() << endl;
    cout << body;
    return 0;
}