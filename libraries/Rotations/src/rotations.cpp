/**
 * @file rotations.cpp
 *
 * @brief rotation in euclidian space
 *
 * @author Siddharth Deore
 * Contact: siddharth.deore@iit.it
 *
 */
#include "rotations.hpp"
#include <cmath>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

namespace Rotations
{
    // Compute rotation about Y axis and return 3X3 Matrix of type Eigen::Matrix3d
    // param : angle in radians.
    // returns rotation matrix 
    Matrix3d rotateX(double angle){
        Matrix3d R(3,3);
        double ca = cos(angle);
        double sa = sin(angle);
        
        R <<    1.0, 0.0, 0.0,
                0.0,  ca, -sa,
                0.0,  sa,  ca;
        return R;
    }

    // Compute rotation about Y axis and return 3X3 Matrix of type Eigen::Matrix3d
    // param : angle in radians.
    // returns rotation matrix 
    Matrix3d rotateY(double angle){
        Matrix3d R(3,3);
        double ca = cos(angle);
        double sa = sin(angle);
        
        R <<    ca,  0.0,  sa,
                0.0, 1.0, 0.0,
                -sa, 0.0,  ca;
        return R;
    }
    
    // Compute rotation about Y axis and return 3X3 Matrix of type Eigen::Matrix3d
    // param : angle in radians.
    // returns rotation matrix 
    Matrix3d rotateZ(double angle){
        Matrix3d R(3,3);
        double ca = cos(angle);
        double sa = sin(angle);
        
        R <<    ca,  -sa, 0.0,
                sa,   ca, 0.0,
                0.0, 0.0, 1.0;
        return R;
    }
    // get Hat Map transformation A.K.A. skew symetric matrix of vector
    Matrix3d getSkew(Vector3d vec) {
        Matrix3d S(3,3);
        S <<    0.0,    -vec[2],    vec[1],
                vec[2],     0.0,   -vec[0],
               -vec[1],  vec[0],       0.0;

        return S;
    }
    // get 4x4 Hat Map transformation A.K.A. skew symetric matrix of vector
    Matrix4d getSkew4(Vector3d vec) {
        Matrix4d S(4,4);
        S <<    0.0,    -vec[2],  -vec[1],  vec[0],
                vec[0],     0.0,   vec[2], -vec[1],
                vec[1], -vec[2],      0.0,  vec[0],
                vec[2],  vec[1],  -vec[0],      0.0;

        return S;
    }
    // compute quaternion deviation between two quaternions
    Quaterniond error_quaternion(Quaterniond q_1,Quaterniond q_2) {
        return q_2 * q_1.inverse();  
    }
    
    // quaternion kinematics, quaternion angular velocity
    Quaterniond velocity_quaternion(Quaterniond q, Vector3d vec){
        Matrix4d Omega(4,4);
        Omega = getSkew4(vec);
        Vector4d qv(q.x(), q.y(), q.z(),q.w());
        return Quaterniond(0.5 * Omega * qv);         
    };
    
    
} // namespace Rotations

