// #include<Eigen/Core>
#include<Eigen/Dense>
#include<iostream>
#include <unsupported/Eigen/MatrixFunctions>
#include <Eigen/Geometry>


int main(int argc, char * argv[])
{
    Eigen::Matrix3d R =  Eigen::Matrix3d::Identity();
    std::cout<< "R: \n"<< R << std::endl;

    Eigen::Vector3d omega(0.01, 0.02, 0.03);
    Eigen::Matrix3d omega_hat; 
    omega_hat << 0, -0.03, 0.02, 0.03, 0, -0.01, -0.02, 0.01, 0;
    std::cout<<"R_rotated: \n" << R * omega_hat.exp() <<std::endl;

    Eigen::Quaterniond q = Eigen::Quaterniond::Identity();
    Eigen::Quaterniond dq;
    dq.w() = 1;
    dq.vec() = omega / 2 ;
    std::cout<<"Quaternion_rotated: \n" << (q*dq).toRotationMatrix() <<std::endl;

    return 0;
}