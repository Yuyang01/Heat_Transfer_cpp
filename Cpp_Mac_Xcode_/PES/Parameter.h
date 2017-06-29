//
//  Parameter.h
//  PES
//
//  Created by Yuyang Wang on 16/5/1.
//  Copyright © 2016年 Yuyang Wang. All rights reserved.
//

#ifndef Parameter_h
#define Parameter_h
#include"Matrix.hpp"
#include"Vector.hpp"

using namespace std;

Vector data(Matrix& X,Matrix &T)
{
    int num=T.GetNumberOfColumns()-1;
    Vector a(6);
    switch (num) {
        case 4:
        {
            if(X.GetNumberOfColumns()==3)
            {
                a(1)=4;
                a(2)=2;
                a(3)=4;
            }
            else{
                a(1)=1;
                a(2)=3;
                a(3)=4;
            }
            break;
        }
        case 8:{
            
            if(X.GetNumberOfColumns()==3)
            {
                a(1)=9;
                a(2)=2;
                a(3)=8;
            }
            else{
                a(1)=8;
                a(2)=3;
                a(3)=8;
            }
            break;
        }
        case 3:{
            
            a(1)=1;
            a(2)=2;
            a(3)=3;
            break;
        }
        case 6:{
            
            a(1)=3;
            a(2)=2;
            a(3)=6;
            
            break;
        }
        case 20:{
            
            a(1)=27;
            a(2)=3;
            a(3)=20;
            
            break;
        }
            
        case 10:{
            
            a(1)=4;
            a(2)=3;
            a(3)=10;
            
            break;
        }
        default:
        {
            cout<<"No such case for the definition of integration parameter"<<endl;
            break;
        }
    }
    a(4)=X.GetNumberOfRows();
    a(5)=T.GetNumberOfRows();
    cout<<"Please input the diffusion coefficient:"<<endl;
    cin>>a(6);
    return a;
}



#endif /* Parameter_h */
