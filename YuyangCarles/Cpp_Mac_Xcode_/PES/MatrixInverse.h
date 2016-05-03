//
//  MatrixInverse.h
//  PES
//
//  Created by Yuyang Wang on 16/5/1.
//  Copyright © 2016年 Yuyang Wang. All rights reserved.
//

#ifndef MatrixInverse_h
#define MatrixInverse_h
#include "Matrix.hpp"
#include"Vector.hpp"

Matrix Inverse(Matrix& Jacob)
{
    int n=Jacob.GetNumberOfRows();
    Matrix invJacob(n,n);
      double det=Jacob.CalculateDeterminant();

    if(n==3)
    {
    Matrix Jacob2=Jacob*Jacob;
  
    double trace1=Jacob.Trace();
    double trace2=Jacob2.Trace();
    
    //define a identity matrix
    Matrix I(n,n);
    for(int i=1;i<=n;i++)
    {
        I(i,i)=0.5*(trace1*trace1-trace2);
        //cout<<"I(i,i)="<<I(i,i)<<endl;
    }
    
    Jacob=Jacob*trace1;
    Jacob=-Jacob;
    Jacob=Jacob2+Jacob+I;
    invJacob=Jacob*(double(1)/det);
        
    }
    else
    {
        Matrix Jacob2=Jacob;
        invJacob(1,1)=(double(1)/det)*Jacob2(2,2);
        invJacob(1,2)=-(double(1)/det)*Jacob2(1,2);
        invJacob(2,1)=-(double(1)/det)*Jacob2(2,1);
        invJacob(2,2)=(double(1)/det)*Jacob2(1,1);
        
    }
   
    return invJacob;
    
}




#endif /* MatrixInverse_h */
