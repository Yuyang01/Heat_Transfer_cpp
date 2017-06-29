//
//  SolveEq.h
//  PES
//
//  Created by Yuyang Wang on 16/5/2.
//  Copyright © 2016年 Yuyang Wang. All rights reserved.
//

#ifndef SolveEq_h
#define SolveEq_h
#include "Vector.hpp"
#include "Matrix.hpp"
#include "linearsystem.hpp"

Vector solve_eq(Matrix& K,Vector& f,Matrix& X,Matrix& T,Matrix& In,Matrix& Out)
{
  
    int dp=In.GetNumberOfColumns()+Out.GetNumberOfColumns();
    Matrix C(dp,2);
    Vector b(dp);
    for(int i=1;i<=In.GetNumberOfColumns();i++)
    {
        
        C(i,1)=In(1,i);
        // cout<<"c should be 1="<<C(i,1)<<endl;
        C(i,2)=1.0;
        b(i)=1.0;
        
    }
    
    for(int i=In.GetNumberOfColumns()+1;i<=dp;i++)
    {
        
        C(i,1)=Out(1,i-In.GetNumberOfColumns());
        //cout<<"c should be 0="<<C(i,1)<<endl;
        C(i,2)=1.0;
        b(i)=0.0;
        
    }
    int neq=length(f);
    
    
    Matrix A(dp,neq);
    for(int i=1;i<=dp;i++)
    {
        
        A(i,C(i,1))=1.0;
        
        
    }
    
    
    Matrix Ktot(neq+dp,neq+dp);
    Vector ftot(neq+dp);
    for(int i=1;i<=length(ftot);i++)
    {
        for(int j=1;j<=length(ftot);j++)
        {
            
            if(i<=neq && j<=neq)
            {
                Ktot(i,j)=K(i,j);
                
            }
            else if(i<=neq && j>neq)
            {
                Ktot(i,j)=A(j-neq,i);
            }
            else if(i>neq && j<= neq)
            {
                Ktot(i,j)=A(i-neq,j);
            }
            else
            {
                Ktot(i,j)=0.0;
                
            }
        }
        
        if(i<=neq)
        {
            ftot(i)=f(i);
            //cout<<"ftot="<<i <<"  ="<<ftot(i)<<endl;
        }
        
        else
        {
            ftot(i)=b(i-neq);
            //cout<<"ftot="<<i <<"  ="<<ftot(i)<<endl;
            
        }
    }
    
    
    
    
    
    
    
    
    LinearSystem sol(Ktot,ftot);
    Vector temp=sol.Solve();
    
    
   
    
    
    return temp;
    
    
}




#endif /* SolveEq_h */
