/**
 * @file rotations.hpp
 *
 * @brief rotation in euclidian space
 *
 * @author Siddharth Deore
 * Contact: siddharth.deore@iit.it
 *
 */
#ifndef _ROTATIONS_H_
#define _ROTATIONS_H_

#include <cmath>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

namespace Rotations
{
    // Compute rotation about X axis and return 3X3 Matrix of type Eigen::Matrix3d
    // param : angle in radians.

    // Rotate X
    Matrix3d rotateX(double);

    // Rotate Y
    Matrix3d rotateY(double);
    
    // Rotate Z
    Matrix3d rotateZ(double);

    // Hat Map matrix (3x3 Skew symetrix matrix of 3d vector)
    Matrix3d getSkew(Vector3d);

    Matrix4d getSkew4(Vector3d);

    // quaternion deviation
    Quaterniond error_quaternion(Quaterniond, Quaterniond);

    // velocity quaternion
    Quaterniond velocity_quaternion(Quaterniond, Vector3d);

    
    
    
} // namespace Rotations

#endif // _ROTATIONS_H_
