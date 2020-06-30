//
//  main.cpp
//  Eigen-Practice
//
//  Created by 盧廉晰 on 2020/3/4.
//  Copyright © 2020 盧廉晰. All rights reserved.
//

#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/SVD>

#include <ctime>

#define MATRIX_SIZE 120
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    Eigen::Matrix<float, 2, 3> matrix_23;
    
    Eigen::Vector3d v_3d;
    
    //Initialize as zeros
    //Eigen::Matrix<double,3,3> == Eigen::Matrix3d
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();
    
    //Uncertain of the size of the matrix --> dynamic matrix
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;
    
    Eigen::MatrixXd matrix_x;
    
    matrix_23 << 1, 2, 3, 4, 5, 6;
    cout << matrix_23 << endl;
    
    //Traverse all elements in matrix_23
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 2; ++j) {
            cout << matrix_23(i,j) << endl;
        }
    }
    
    v_3d << 3, 2, 1;
    
    //Cast into different type
    Eigen::Matrix<double, 2, 1> result1 = matrix_23.cast<double>() * v_3d;
    cout << result1 << endl;
    
    Eigen::Matrix<float, 2, 1> result2 = matrix_23 * v_3d.cast<float>();
    cout << result2 << endl;
    
    //Some matrix operation
    matrix_33 = Eigen::Matrix3d::Random();
    cout << matrix_33 << endl;
    cout << matrix_33.transpose() << endl;
    cout << matrix_33.sum() << endl;
    cout << matrix_33.trace() << endl;
    cout << 10*matrix_33 << endl;
    cout << matrix_33.inverse() << endl;
    cout << matrix_33.determinant() << endl;
    
    //Solve Eigen Values & Eigen Vectors
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver(matrix_33.transpose()*matrix_33);
    cout << "Eigen Values: " << eigen_solver.eigenvalues() << endl;
    cout << "Eigen Vectors: " << eigen_solver.eigenvectors() << endl;
    
    Eigen::Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN;
    matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    Eigen::Matrix<double, MATRIX_SIZE, 1> v_Nd;
    v_Nd = Eigen::MatrixXd::Random(MATRIX_SIZE, 1);
    
    clock_t time_stt = clock();
    //Inverse Directly
    Eigen::MatrixXd x = matrix_NN.inverse()*v_Nd;
    cout << "Time use in normal inverse is " << 1000 * (clock() - time_stt) / (double)CLOCKS_PER_SEC << "ms" << endl;
    
    //QR Solver
    time_stt = clock();
    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout << "Time use in QR Decomposition is " << 1000 * (clock() -time_stt) / (double)CLOCKS_PER_SEC << "ms" << endl;
    
    //Singular Value Decomposition
    Eigen::MatrixXd m = Eigen::MatrixXd::Random(3, 2);
    cout << "Here is the matrix: \n" << m << endl;
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(m, Eigen::ComputeThinU | Eigen::ComputeThinV);
    cout << "It's singular values are: \n" << svd.singularValues() << endl;
    cout << svd.computeU() << endl;
    cout << svd.computeV() << endl;
    cout << "It's left singular vectors are the columns of the thin U matrix: \n" << svd.matrixU() << endl;
    cout << "It's right singular vectors are the columns of the thin V matrix: \n" << svd.matrixV() << endl;
    
    //Acess a row or a column of a matrix
    m = Eigen::MatrixXd::Random(3, 3);
    cout << "Here is the matrix: \n" << m << endl;
    Eigen::Vector3d v_row1 = m.row(0);
    cout << "The first row: \n" << v_row1.transpose() << endl;
    //or
    cout << "The first row by block: \n" << m.block(0,0,1,3) << endl; //(0,0,1,3) stands for starting from element(0,0) access a block with the size (1,3)
    
    Eigen::Vector3d v_col1 = m.col(0);
    cout << "The first column: \n" << v_col1 << endl;
    
    
    
    return 0;
}
