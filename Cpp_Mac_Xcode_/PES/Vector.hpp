//
//  Vector.hpp
//  PES
//
//  Created by Yuyang Wang on 16/4/30.
//  Copyright © 2016年 Yuyang Wang. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>



class Vector
{
protected:
    double* mData; // data stored in vector
    int mSize; // size of vector
public:
    //Vector();
    Vector(const Vector& otherVector);
    Vector(int size);
    ~Vector();
    int GetSize() const;
    double& operator[](int i); // zero-based indexing
    // read-only zero-based indexing
    double Read(int i) const;
    double& operator()(int i); // one-based indexing
    // assignment
    Vector& operator=(const Vector& otherVector);
    Vector operator+() const; // unary +
    Vector operator-() const; // unary -
    Vector operator+(const Vector& v1) const; // binary +
    Vector operator-(const Vector& v1) const; // binary -
    // scalar multiplication
    Vector operator*(double a) const;
    // p-norm method
    double CalculateNorm(int p=2) const;
    // declare length function as a friend
    friend int length(const Vector& v);
};

// Prototype signature of length() friend function
int length(const Vector& v);

#endif /* Vector_hpp */
