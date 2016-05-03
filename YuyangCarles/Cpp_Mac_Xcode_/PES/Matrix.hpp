//
//  Matrix.hpp
//  PES
//
//  Created by Yuyang Wang on 16/4/30.
//  Copyright © 2016年 Yuyang Wang. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include "Vector.hpp"

class Matrix
{
protected:
    double** mData; // entries of matrix
    int mNumRows, mNumCols; // dimensions
public:
    Matrix();
    Matrix(const Matrix& otherMatrix);
    Matrix(int numRows, int numCols);
    Matrix(char* filename);
    ~Matrix();
    int GetNumberOfRows() const;
    int GetNumberOfColumns() const;
    double& operator()(int i, int j); //1-based indexing
    //overloaded assignment operator
    Matrix& operator=(const Matrix& otherMatrix);
    Matrix operator+() const; // unary +
    Matrix operator-() const; // unary -
    Matrix operator+(const Matrix& m1) const; // binary +
    Matrix operator-(const Matrix& m1) const; // binary -
    // scalar multiplication
    Matrix operator*(double a) const;
    double CalculateDeterminant() const;
    // compute the trace of the matrix
    double Trace() const;
    // declare vector multiplication friendship
    friend Vector operator*(const Matrix& m,const Vector& v);
    friend Vector operator*(const Vector& v,const Matrix& m);
    friend Matrix operator*(const Matrix& m,const Matrix& v);
};
// prototype signatures for friend operators
Vector operator*(const Matrix& m, const Vector& v);
Vector operator*(const Vector& v, const Matrix& m);
Matrix operator*(const Matrix& m,const Matrix& v);


#endif /* Matrix_hpp */
