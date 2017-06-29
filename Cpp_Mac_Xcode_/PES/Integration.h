//
//  Integration.h
//  PES
//
//  Created by Yuyang Wang on 16/5/1.
//  Copyright © 2016年 Yuyang Wang. All rights reserved.
//

#ifndef Integration_h
#define Integration_h

#include"Matrix.hpp"
#include"Vector.hpp"

using namespace std;


Vector weight(Matrix& X,Matrix &T,Vector& pp)
{
    Vector ww(pp(1));
    
    int num=T.GetNumberOfColumns()-1;
        switch (num)
    
    {
        case 4:
        {
            if(X.GetNumberOfColumns()==3)
            {
                ww(1)=1.0;
                ww(2)=1.0;
                ww(3)=1.0;
                ww(4)=1.0;
            }
            else
            {
                ww(1)=1.0/6.0;
            }
            break;
        }
            
        case 8:
        {
            
            if(X.GetNumberOfColumns()==3)
            {
                Vector w1d(3);
                w1d(1)=0.555555555;
                w1d(2)=0.888888888;
                w1d(3)=0.555555555;
                for(int j=1;j<=3;j++)
                {
                    for(int i=1;i<=3;i++)
                    {
                        int n=3*(j-1)+i;
                        ww(n)=w1d(i)*w1d(j);
                    }
                }
                
               
            }
            else
            {
                ww(1)=1.0;
                ww(2)=1.0;
                ww(3)=1.0;
                ww(4)=1.0;
                ww(5)=1.0;
                ww(6)=1.0;
                ww(7)=1.0;
                ww(8)=1.0;
            }
            break;
        }
        case 3:
        {
            
            ww(1)=0.5;
            break;
        }
        case 6:
        {
            
            ww(1)=1./6.;
            ww(2)=1.0/6.0;
            ww(3)=1.0/6.0;
            
            break;
            
        }
        case 20:{
            
            Vector w1d(3);
            w1d(1)=0.555555555;
            w1d(2)=0.888888888;
            w1d(3)=0.555555555;
            for(int k=1;k<=3;k++)
            {
                for(int j=1;j<=3;j++)
                {
                    for(int i=1;i<=3;i++)
                    {
                        int n=9*(k-1)+3*(j-1)+i;
                        ww(n)=w1d(i)*w1d(j)*w1d(k);
                    }
                }
            }
           
            
            break;
        }
            
        case 10:{
            
            ww(1)=1.0/24.0;
            ww(2)=1.0/24.0;
            ww(3)=1.0/24.0;
            ww(4)=1.0/24.0;
            
            break;
        }
        default:
        {
            cout<<"No such case for defining weighting"<<endl;
            break;
        }
    }
    
    return ww;
    
}





Matrix shape_xi(Matrix& X,Matrix &T,Vector& pp)
{
    Matrix xxi(pp(1),pp(2));
    
    
    
    int num=T.GetNumberOfColumns()-1;
    switch (num) {
        case 4:
        {
            if(X.GetNumberOfColumns()==3)
            {
                xxi(1,1) = -0.5773502692;
                xxi(1,2) = xxi(1,1);
                xxi(2,1) = -xxi(1,1);
                xxi(2,2) = xxi(1,1);
                xxi(3,1) = xxi(1,1);
                xxi(3,2) = -xxi(1,1);
                xxi(4,1) = -xxi(1,1);
                xxi(4,2) = -xxi(1,1);
            }
            else{
                xxi(1,1) = 0.25;
                xxi(1,2) = 0.25;
                xxi(1,3) = 0.25;
            }
            break;
        }
        case 8:{
            
            if(X.GetNumberOfColumns()==3)
            {
                xxi(1,1) = -0.7745966692;
                xxi(1,2) = xxi(1,1);
                xxi(2,1) = 0.0;
                xxi(2,2) = xxi(1,1);
                xxi(3,1) = -xxi(1,1);
                xxi(3,2) = xxi(1,1);
                xxi(4,1) = xxi(1,1);
                xxi(4,2) = 0.0;
                
                xxi(5,1) = 0.0;
                xxi(5,2) = 0.0;
                xxi(6,1) =-xxi(1,1) ;
                xxi(6,2) = 0.0;
                xxi(7,1) = xxi(1,1);
                xxi(7,2) = -xxi(1,1);
                xxi(8,1) = 0.0;
                xxi(8,2) = -xxi(1,1);
                xxi(9,1) = -xxi(1,1);
                xxi(9,2) = -xxi(1,1);
            }
            else
            {
                
                Vector x1d(3);
                x1d(1)=0.555555555;
                x1d(2)=0.888888888;
                x1d(3)=0.555555555;
                for(int k=1;k<=2;k++)
                {
                    for(int j=1;j<=2;j++)
                    {
                        for(int i=1;i<=2;i++)
                        {
                            int n=4*(k-1)+2*(j-1)+i;
                            xxi(n,1) = x1d(i);
                            xxi(n,2) = x1d(j);
                            xxi(n,3) = x1d(k);
                        }
                    }
                }
               
                
            }
            break;
        }
        case 3:
        {
            
            xxi(1,1) = 1.0/3.0;
            xxi(1,2) = 1.0/3.0;
            break;
        }
        case 6:
        {
            
            xxi(1,1) = 0.6;
            xxi(1,2) = 0.2;
            xxi(2,1) = 0.2;
            xxi(2,2) = 0.6;
            xxi(3,1) = 0.2;
            xxi(3,2) = 0.2;
            
            break;
        }
        case 20:{
            
            Vector x1d(3);
            x1d(1)=-0.7745966692;
            x1d(2)=0.0;
            x1d(3)=0.7745966692;
            for(int k=1;k<=3;k++)
            {
                for(int j=1;j<=3;j++)
                {
                    for(int i=1;i<=3;i++)
                    {
                        int n=9*(k-1)+3*(j-1)+i;
                        xxi(n,1) = x1d(i);
                        xxi(n,2) = x1d(j);
                        xxi(n,3) = x1d(k);
                    }
                }
            }
           
            
            break;
        }
            
        case 10:{
            
            xxi(1,1) = 0.58541020;
            xxi(1,2) = 0.13819660;
            xxi(1,3) = xxi(1,2);
            xxi(2,1) = xxi(1,2);
            xxi(2,2) = xxi(1,1);
            xxi(2,3) = xxi(1,2);
            xxi(3,1) = xxi(1,2);
            xxi(3,2) = xxi(1,2);
            xxi(3,3) = xxi(1,1);
            xxi(4,1) = xxi(1,2);
            xxi(4,2) = xxi(1,2);
            xxi(4,3) = xxi(1,2);
            
            break;
        }
        default:
        {
            cout<<"No such case for defining integration point"<<endl;
            break;
        }
    }
    
    
    
    
    
    return xxi;
}




#endif /* Integration_h */
