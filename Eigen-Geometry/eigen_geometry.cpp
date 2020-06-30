//
//  main.cpp
//  EigenGeometry
//
//  Created by 盧廉晰 on 2020/3/17.
//  Copyright © 2020 盧廉晰. All rights reserved.
//

#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
using namespace std;
int main(int argc, const char * argv[]) {
    //Rotation Matrix
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
   
    //AngleAxis
    Eigen::AngleAxisd angle_axis_vec (M_PI/4, Eigen::Vector3d (0,0,1)); //Rotate 45 degree around the z-axis
    //cout .percision(3);
    cout << "rotation matrix = \n" << angle_axis_vec.matrix() << endl; //matrix() (w1, w2, w3).T --> R
    rotation_matrix = angle_axis_vec.toRotationMatrix();
    cout << "rotation matrix = \n" << rotation_matrix << endl; //toRotationMatrix
    
    //Use Angle-Axis to rotate a 3D point
    Eigen::Vector3d v(1,0,0);
    Eigen::Vector3d v_rotated = angle_axis_vec * v;
    cout <<"(1, 0, 0) after rotation = \n" << v_rotated << endl;
    
    //Use Rotation Matrix to rotate a 3D point
    v_rotated = rotation_matrix * v;
    cout <<"(1, 0, 0) after rotation = \n" << v_rotated << endl;
    
    //Euler Angle
    //Transform the rotation matrix into Euler angle
    Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2,1, 0); //In the sequence of ZYX
    cout << "yaw pitch roll = \n" << euler_angles << endl;
    
    //Transformation matrix
    Eigen::Isometry3d T = Eigen::Isometry3d::Identity(); // 4 x 4 Transformation matrix
    T.rotate(angle_axis_vec); //Use angle-axis to rotate
    T.pretranslate(Eigen::Vector3d(1,3,4)); //Make the
    cout << "Transform matrix = \n" << T.matrix() << endl;
    
    //Transform a point by the transformation matrix
    Eigen::Vector3d v_transformed = T*v;
    cout << "v transformed = \n" << v_transformed << endl;
    
    //Quaternion
    //pass in Angle-Axis to Quaternion
    Eigen::Quaterniond q = Eigen::Quaterniond(angle_axis_vec);
    cout << "quaternion = \n" << q.coeffs() << endl; //(x, y, z, w), w is the real part, x,y,z are the imaginary part
    
    //pass in Rotation Matrix to Quaternion
    q = Eigen::Quaterniond(rotation_matrix);
    cout << "quaternion = \n" << q.coeffs() << endl;
    
    //Use Quaternion to rotation a point
    v_rotated = q*v; //overloaded *
    cout << "(1, 0, 0) after rotation = \n" << v_rotated << endl; 
    
    return 0;
}
