//
//  linearsystem.hpp
//  PES
//
//  Created by Yuyang Wang on 16/4/30.
//  Copyright © 2016年 Yuyang Wang. All rights reserved.
//

#ifndef linearsystem_hpp
#define linearsystem_hpp

#include <stdio.h>
#include "Vector.hpp"
#include "Matrix.hpp"

class LinearSystem
{
private:
    int mSize; // size of linear system
    Matrix* mpA;  // matrix for linear system
    Vector* mpb;  // vector for linear system
    
    // Only allow constructor that specifies matrix and
    // vector to be used.  Copy constructor is private.
    LinearSystem(const LinearSystem& otherLinearSystem){};
public:
    LinearSystem(const Matrix& A, const Vector& b);
    
    // destructor frees memory allocated
    ~LinearSystem();
    
    // Method for solving system
    virtual Vector Solve();
};


#endif /* linearsystem_hpp */
