//
//  shapeFunction.h
//  PES
//
//  Created by Yuyang Wang on 16/5/1.
//  Copyright © 2016年 Yuyang Wang. All rights reserved.
//

#ifndef shapeFunction_h
#define shapeFunction_h

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cmath>
using namespace std;


Matrix shape_N(Matrix& X,Matrix &T,Matrix& xi,Vector& pp)
{
    Matrix NN(pp(1),pp(3));
    
    
    
    int num=T.GetNumberOfColumns()-1;
    switch (num) {
        case 4:
        {
            if(X.GetNumberOfColumns()==3)
            {
                for(int i1=1;i1<=pp(1);i1++)
                {
                    NN(i1,1) = 0.25*(1.-xi(i1,1))*(1.-xi(i1,2));
                    NN(i1,2) = 0.25*(1.+xi(i1,1))*(1.-xi(i1,2));
                    NN(i1,3) = 0.25*(1.+xi(i1,1))*(1.+xi(i1,2));
                    NN(i1,4) = 0.25*(1.-xi(i1,1))*(1.+xi(i1,2));
                }
            }
            else{
                
                for(int i1=1;i1<=pp(1);i1++)
                {
                    NN(1,1) =   xi(1,1);
                    NN(1,2) =   xi(1,2);
                    NN(1,3) =   xi(1,3);
                    NN(1,4) = 1.0-xi(1,1)-xi(1,2)-xi(1,3);
                }
                
            }
            break;
        }
        case 8:{
            
            if(X.GetNumberOfColumns()==3)
            {
                
                for(int i1=1;i1<=pp(1);i1++)
                {
                    NN(i1,1) = -0.25*(1.-xi(i1,1))*(1.-xi(i1,2))*(1.+xi(i1,1)+xi(i1,2));
                    NN(i1,2) = 0.25*(1.+xi(i1,1))*(1.-xi(i1,2))*(xi(i1,1)-xi(i1,2)-1.);
                    NN(i1,3) = 0.25*(1.+xi(i1,1))*(1.+xi(i1,2))*(xi(i1,1)+xi(i1,2)-1.);
                    NN(i1,4) = 0.25*(1.-xi(i1,1))*(1.+xi(i1,2))*(xi(i1,2)-xi(i1,1)-1.);
                    
                    NN(i1,5) = 0.5*(1.-xi(i1,1)*xi(i1,1))*(1.-xi(i1,2));
                    NN(i1,6) = 0.5*(1.+xi(i1,1))*(1.-xi(i1,2)*xi(i1,2));
                    NN(i1,7) = 0.5*(1.-xi(i1,1)*xi(i1,1))*(1.+xi(i1,2));
                    NN(i1,8) = 0.5*(1.-xi(i1,1))*(1.-xi(i1,2)*xi(i1,2));
                }
            }
            else
            {
                
                for(int i1=1;i1<=pp(1);i1++)
                {
                    NN(i1,1) = (1.-xi(i1,1))*(1.-xi(i1,2))*(1.-xi(i1,3))/8.;
                    NN(i1,2) = (1.+xi(i1,1))*(1.-xi(i1,2))*(1.-xi(i1,3))/8.;
                    NN(i1,3) = (1.+xi(i1,1))*(1.+xi(i1,2))*(1.-xi(i1,3))/8.;
                    NN(i1,4) = (1.-xi(i1,1))*(1.+xi(i1,2))*(1.-xi(i1,3))/8.;
                    NN(i1,5) = (1.-xi(i1,1))*(1.-xi(i1,2))*(1.+xi(i1,3))/8.;
                    NN(i1,6) = (1.+xi(i1,1))*(1.-xi(i1,2))*(1.+xi(i1,3))/8.;
                    NN(i1,7) = (1.+xi(i1,1))*(1.+xi(i1,2))*(1.+xi(i1,3))/8.;
                    NN(i1,8) = (1.-xi(i1,1))*(1.+xi(i1,2))*(1.+xi(i1,3))/8.;
                }
                
            }
            
            break;
        }
            
            
        case 3:
        {
            
            
            for(int i1=1;i1<=pp(1);i1++)
            {
                NN(1,1) =   xi(1,1);
                NN(1,2) =   xi(1,2);
                NN(1,3) = 1.0-  xi(1,1)-  xi(1,2);
            }
            
            break;
        }
        case 6:
        {
            
            
            for(int i1=1;i1<=pp(1);i1++)
            {
                double xi3 = 1.-xi(i1,1)-xi(i1,2);
                NN(i1,1) = (2.*xi(i1,1)-1.)*xi(i1,1);
                NN(i1,2) = (2.*xi(i1,2)-1.)*xi(i1,2);
                NN(i1,3) = (2.*xi3-1.)*xi3;
                NN(i1,4) = 4.*xi(i1,1)*xi(i1,2);
                NN(i1,5) = 4.*xi(i1,2)*xi3;
                NN(i1,6) = 4.*xi3*xi(i1,1);
            }
            
            break;
        }
        case 20:{
            
            
            for(int i1=1;i1<=pp(1);i1++)
            {
                NN(i1,1) = (1.-xi(i1,1))*(1.-xi(i1,2))*(1.-xi(i1,3))*(-xi(i1,1)-xi(i1,2)-xi(i1,3)-2.)/8.;
                NN(i1,2) = (1.+xi(i1,1))*(1.-xi(i1,2))*(1.-xi(i1,3))*(xi(i1,1)-xi(i1,2)-xi(i1,3)-2.)/8.;
                NN(i1,3) = (1.+xi(i1,1))*(1.+xi(i1,2))*(1.-xi(i1,3))*(xi(i1,1)+xi(i1,2)-xi(i1,3)-2.)/8.;
                NN(i1,4) = (1.-xi(i1,1))*(1.+xi(i1,2))*(1.-xi(i1,3))*(-xi(i1,1)+xi(i1,2)-xi(i1,3)-2.)/8.;
                NN(i1,5) = (1.-xi(i1,1))*(1.-xi(i1,2))*(1.+xi(i1,3))*(-xi(i1,1)-xi(i1,2)+xi(i1,3)-2.)/8.;
                NN(i1,6) = (1.+xi(i1,1))*(1.-xi(i1,2))*(1.+xi(i1,3))*(xi(i1,1)-xi(i1,2)+xi(i1,3)-2.)/8.;
                NN(i1,7) = (1.+xi(i1,1))*(1.+xi(i1,2))*(1.+xi(i1,3))*(xi(i1,1)+xi(i1,2)+xi(i1,3)-2.)/8.;
                NN(i1,8) = (1.-xi(i1,1))*(1.+xi(i1,2))*(1.+xi(i1,3))*(-xi(i1,1)+xi(i1,2)+xi(i1,3)-2.)/8.;
                NN(i1,9)  = (1.-(double)(pow(xi(i1,1),2)))*(1.-xi(i1,2))*(1.-xi(i1,3))/4.;
                NN(i1,10) = (1.+xi(i1,1))*(1.-(double)(pow(xi(i1,2),2)))*(1.-xi(i1,3))/4.;
                NN(i1,11) = (1.-(double)(pow(xi(i1,1),2)))*(1.+xi(i1,2))*(1.-xi(i1,3))/4.;
                NN(i1,12) = (1.-xi(i1,1))*(1.-(double)(pow(xi(i1,2),2)))*(1.-xi(i1,3))/4.;
                NN(i1,13) = (1.-(double)(pow(xi(i1,1),2)))*(1.-xi(i1,2))*(1.+xi(i1,3))/4.;
                NN(i1,14) = (1.+xi(i1,1))*(1.-(double)(pow(xi(i1,2),2)))*(1.+xi(i1,3))/4.;
                NN(i1,15) = (1.-(double)(pow(xi(i1,1),2)))*(1.+xi(i1,2))*(1.+xi(i1,3))/4.;
                NN(i1,16) = (1.-xi(i1,1))*(1.-(double)(pow(xi(i1,2),2)))*(1.+xi(i1,3))/4.;
                NN(i1,17) = (1.-xi(i1,1))*(1.-xi(i1,2))*(1.-(double)(pow(xi(i1,3),2)))/4.;
                NN(i1,18) = (1.+xi(i1,1))*(1.-xi(i1,2))*(1.-(double)(pow(i1,3),2))/4.;
                NN(i1,19) = (1.+xi(i1,1))*(1.+xi(i1,2))*(1.-(double)(pow(xi(i1,3),2)))/4.;
                NN(i1,20) = (1.-xi(i1,1))*(1.+xi(i1,2))*(1.-(double)(pow(xi(i1,3),2)))/4.;
            }
            break;
        }
            
        case 10:{
            
            for(int i1=1;i1<=pp(1);i1++)
            {
                double xi4 = 1.-xi(i1,1)-xi(i1,2)-xi(i1,3);
                NN(i1,1) = (2.0*xi(i1,1)-1.)*xi(i1,1);
                NN(i1,2) = (2.0*xi(i1,2)-1.)*xi(i1,2);
                NN(i1,3) = (2.0*xi(i1,3)-1.)*xi(i1,3);
                NN(i1,4) = (2.0*xi4-1.)*xi4;
                NN(i1,5) = 4.0*xi(i1,1)*xi(i1,2);
                NN(i1,6) = 4.0*xi(i1,2)*xi(i1,3);
                NN(i1,7) = 4.0*xi(i1,3)*xi(i1,1);
                NN(i1,8) = 4.0*xi(i1,1)*xi4;
                NN(i1,9) = 4.0*xi(i1,2)*xi4;
                NN(i1,10) = 4.0*xi(i1,3)*xi4;
            }
            
            break;
        }
        default:
        {
            cout<<"No such case for defining shape function"<<endl;
            break;
        }
    }
    
    
    
    
    
    return NN;
    
}


Matrix shape_dN(Matrix& X,Matrix &T,Matrix& xi,Vector& pp)
{
    Matrix dNdxi(pp(1)*pp(2),pp(3));
    
    
    int num=T.GetNumberOfColumns()-1;
    switch (num) {
        case 4:
        {
            if(X.GetNumberOfColumns()==3)
            {
                for(int i1=1;i1<=pp(1);i1++)
                {
                    dNdxi(i1*2-1,1) = -0.25*(1.-xi(i1,2));
                    dNdxi(i1*2,1) = -0.25*(1.-xi(i1,1));
                    dNdxi(i1*2-1,2) = 0.25*(1.-xi(i1,2));
                    dNdxi(i1*2,2) = -0.25*(1.+xi(i1,1));
                    dNdxi(i1*2-1,3) = 0.25*(1.+xi(i1,2));
                    dNdxi(i1*2,3) = 0.25*(1.+xi(i1,1));
                    dNdxi(i1*2-1,4) = -0.25*(1.+xi(i1,2));
                    dNdxi(i1*2,4) = 0.25*(1.-xi(i1,1));                }
            }
            else{
                
                for(int i1=1;i1<=pp(1);i1++)
                {
                    dNdxi(1,1) = 1.0;
                    dNdxi(2,2) = 1.0;
                    dNdxi(3,3) = 1.0;
                    dNdxi(1,4) = -1.0;
                    dNdxi(2,4) = -1.0;
                    dNdxi(3,4) = -1.0;
                }
                
            }
            break;
        }
        case 8:{
            
            if(X.GetNumberOfColumns()==3)
            {
                
                for(int i1=1;i1<=pp(1);i1++)
                {
                    dNdxi(i1*2-1,1) = 0.25*(1.-xi(i1,2))*(2.*xi(i1,1)+xi(i1,2));
                    dNdxi(i1*2,1) = 0.25*(1.-xi(i1,1))*(xi(i1,1)+2.*xi(i1,2));
                    dNdxi(i1*2-1,2) = 0.25*(1.-xi(i1,2))*(2.*xi(i1,1)-xi(i1,2));
                    dNdxi(i1*2,2) = 0.25*(1.+xi(i1,1))*(2.*xi(i1,2)-xi(i1,1));
                    dNdxi(i1*2-1,3) = 0.25*(1.+xi(i1,2))*(2.*xi(i1,1)+xi(i1,2));
                    dNdxi(i1*2,3) = 0.25*(1.+xi(i1,1))*(2.*xi(i1,2)+xi(i1,1));
                    dNdxi(i1*2-1,4) = 0.25*(1.+xi(i1,2))*(2.*xi(i1,1)-xi(i1,2));
                    dNdxi(i1*2,4) =  0.25*(1.-xi(i1,1))*(2.*xi(i1,2)-xi(i1,1));
                    
                    dNdxi(i1*2-1,5) = -xi(i1,1)*(1.-xi(i1,2));
                    dNdxi(i1*2,5) = -0.5*(1.-xi(i1,1)*xi(i1,1));
                    dNdxi(i1*2-1,6) = 0.5*(1.-xi(i1,2)*xi(i1,2));
                    dNdxi(i1*2,6) = -(1.+xi(i1,1))*xi(i1,2);
                    dNdxi(i1*2-1,7) = -xi(i1,1)*(1.+xi(i1,2));
                    dNdxi(i1*2,7) = 0.5*(1.-xi(i1,1)*xi(i1,1));
                    dNdxi(i1*2-1,8) = -0.5*(1.-xi(i1,2)*xi(i1,2));
                    dNdxi(i1*2,8) = -(1.-xi(i1,1))*xi(i1,2);                }
            }
            else
            {
                
                for(int i1=1;i1<=pp(1);i1++)
                {dNdxi(i1*3-2,1) = -(1.-xi(i1,2))*(1.-xi(i1,3))/8.;
                    dNdxi(i1*3-1,1) = -(1.-xi(i1,1))*(1.-xi(i1,3))/8.;
                    dNdxi(i1*3,1) = -(1.-xi(i1,1))*(1.-xi(i1,2))/8.;
                    dNdxi(i1*3-2,2) = (1.-xi(i1,2))*(1.-xi(i1,3))/8.;
                    dNdxi(i1*3-1,2) = -(1.+xi(i1,1))*(1.-xi(i1,3))/8.;
                    dNdxi(i1*3,2) = -(1.+xi(i1,1))*(1.-xi(i1,2))/8.;
                    dNdxi(i1*3-2,3) = (1.+xi(i1,2))*(1.-xi(i1,3))/8.;
                    dNdxi(i1*3-1,3) = (1.+xi(i1,1))*(1.-xi(i1,3))/8.;
                    dNdxi(i1*3,3) = -(1.+xi(i1,1))*(1.+xi(i1,2))/8.;
                    dNdxi(i1*3-2,4) = -(1.+xi(i1,2))*(1.-xi(i1,3))/8.;
                    dNdxi(i1*3-1,4) = (1.-xi(i1,1))*(1.-xi(i1,3))/8.;
                    dNdxi(i1*3,4) = -(1.-xi(i1,1))*(1.+xi(i1,2))/8.;
                    dNdxi(i1*3-2,5) = -(1.-xi(i1,2))*(1.+xi(i1,3))/8.;
                    dNdxi(i1*3-1,5) = -(1.-xi(i1,1))*(1.+xi(i1,3))/8.;
                    dNdxi(i1*3,5) = (1.-xi(i1,1))*(1.-xi(i1,2))/8.;
                    dNdxi(i1*3-2,6) = (1.-xi(i1,2))*(1.+xi(i1,3))/8.;
                    dNdxi(i1*3-1,6) = -(1.+xi(i1,1))*(1.+xi(i1,3))/8.;
                    dNdxi(i1*3,6) = (1.+xi(i1,1))*(1.-xi(i1,2))/8.;
                    dNdxi(i1*3-2,7) = (1.+xi(i1,2))*(1.+xi(i1,3))/8.;
                    dNdxi(i1*3-1,7) = (1.+xi(i1,1))*(1.+xi(i1,3))/8.;
                    dNdxi(i1*3,7) = (1.+xi(i1,1))*(1.+xi(i1,2))/8.;
                    dNdxi(i1*3-2,8) = -(1.+xi(i1,2))*(1.+xi(i1,3))/8.;
                    dNdxi(i1*3-1,8) = (1.-xi(i1,1))*(1.+xi(i1,3))/8.;
                    dNdxi(i1*3,8) = (1.-xi(i1,1))*(1.+xi(i1,2))/8.;                  }
                
            }
            
            break;
        }
            
            
        case 3:
        {
            
            
            for(int i1=1;i1<=pp(1);i1++)
            {
                dNdxi(i1*2-1,1) = 1.0;
                dNdxi(i1*2,2) = 1.0;
                dNdxi(i1*2-1,3) = -1.0;
                dNdxi(i1*2,3) = -1.0;
            }
            
            break;
        }
        case 6:
        {
            
            
            for(int i1=1;i1<=pp(1);i1++)
            {
                double xi3 = 1.-xi(i1,1)-xi(i1,2);
                dNdxi(i1*2-1,1) = 4.*xi(i1,1)-1.;
                dNdxi(i1*2,2) = 4.*xi(i1,2)-1.;
                dNdxi(i1*2-1,3) = -(4.*xi3-1.);
                dNdxi(i1*2,3) = -(4.*xi3-1.);
                dNdxi(i1*2-1,4) = 4.*xi(i1,2);
                dNdxi(i1*2,4) = 4.*xi(i1,1);
                dNdxi(i1*2-1,5) = -4.*xi(i1,2);
                dNdxi(i1*2,5) = -4.*(-1.+xi(i1,1)+2.*xi(i1,2));
                dNdxi(i1*2-1,6) = -4.*(-1.+2.*xi(i1,1)+xi(i1,2));
                dNdxi(i1*2,6) = -4.*xi(i1,1);
            }
            
            break;
        }
        case 20:{
            
            
            for(int i1=1;i1<=pp(1);i1++)
            {dNdxi(3*i1-2,1) = (-(1.-xi(i1,2))*(1.-xi(i1,3))*(-xi(i1,1)-xi(i1,2)-xi(i1,3)-2.)-(1.-xi(i1,1))*(1.-xi(i1,2))*(1.-xi(i1,3)))/8.;
                dNdxi(3*i1-1,1) = (-(1.-xi(i1,1))*(1.-xi(i1,3))*(-xi(i1,1)-xi(i1,2)-xi(i1,3)-2.)-(1.-xi(i1,1))*(1.-xi(i1,2))*(1.-xi(i1,3)))/8.;
                dNdxi(3*i1,1) = (-(1.-xi(i1,1))*(1.-xi(i1,2))*(-xi(i1,1)-xi(i1,2)-xi(i1,3)-2.)-(1.-xi(i1,1))*(1.-xi(i1,2))*(1.-xi(i1,3)))/8.;
                
                dNdxi(3*i1-2,2) = ((1.-xi(i1,2))*(1.-xi(i1,3))*(xi(i1,1)-xi(i1,2)-xi(i1,3)-2.)+(1.+xi(i1,1))*(1.-xi(i1,2))*(1.-xi(i1,3)))/8.;
                dNdxi(3*i1-1,2) = (-(1.+xi(i1,1))*(1.-xi(i1,3))*(xi(i1,1)-xi(i1,2)-xi(i1,3)-2.)-(1.+xi(i1,1))*(1.-xi(i1,2))*(1.-xi(i1,3)))/8.;
                dNdxi(3*i1,2) = (-(1.+xi(i1,1))*(1.-xi(i1,2))*(xi(i1,1)-xi(i1,2)-xi(i1,3)-2.)-(1.+xi(i1,1))*(1.-xi(i1,2))*(1.-xi(i1,3)))/8.;
                
                dNdxi(3*i1-2,3) = ((1.+xi(i1,2))*(1.-xi(i1,3))*(xi(i1,1)+xi(i1,2)-xi(i1,3)-2.)+(1.+xi(i1,1))*(1.+xi(i1,2))*(1.-xi(i1,3)))/8.;
                dNdxi(3*i1-1,3) = ((1.+xi(i1,1))*(1.-xi(i1,3))*(xi(i1,1)+xi(i1,2)-xi(i1,3)-2.)+(1.+xi(i1,1))*(1.+xi(i1,2))*(1.-xi(i1,3)))/8.;
                dNdxi(3*i1,3) = (-(1.+xi(i1,1))*(1.+xi(i1,2))*(xi(i1,1)+xi(i1,2)-xi(i1,3)-2.)-(1.+xi(i1,1))*(1.+xi(i1,2))*(1.-xi(i1,3)))/8.;
                
                dNdxi(3*i1-2,4) = (-(1.+xi(i1,2))*(1.-xi(i1,3))*(-xi(i1,1)+xi(i1,2)-xi(i1,3)-2.)-(1.-xi(i1,1))*(1.+xi(i1,2))*(1.-xi(i1,3)))/8.;
                dNdxi(3*i1-1,4) = ((1.-xi(i1,1))*(1.-xi(i1,3))*(-xi(i1,1)+xi(i1,2)-xi(i1,3)-2.)+(1.-xi(i1,1))*(1.+xi(i1,2))*(1.-xi(i1,3)))/8.;
                dNdxi(3*i1,4) = (-(1.-xi(i1,1))*(1.+xi(i1,2))*(-xi(i1,1)+xi(i1,2)-xi(i1,3)-2.)-(1.-xi(i1,1))*(1.+xi(i1,2))*(1.-xi(i1,3)))/8.;
                dNdxi(3*i1-2,5) = (-(1.-xi(i1,2))*(1.+xi(i1,3))*(-xi(i1,1)-xi(i1,2)+xi(i1,3)-2.)-(1.-xi(i1,1))*(1.-xi(i1,2))*(1.+xi(i1,3)))/8.;
                dNdxi(3*i1-1,5) = (-(1.-xi(i1,1))*(1.+xi(i1,3))*(-xi(i1,1)-xi(i1,2)+xi(i1,3)-2.)-(1.-xi(i1,1))*(1.-xi(i1,2))*(1.+xi(i1,3)))/8.;
                dNdxi(3*i1,5) = ((1.-xi(i1,1))*(1.-xi(i1,2))*(-xi(i1,1)-xi(i1,2)+xi(i1,3)-2.)+(1.-xi(i1,1))*(1.-xi(i1,2))*(1.+xi(i1,3)))/8.;
                dNdxi(3*i1-2,6) = ((1.-xi(i1,2))*(1.+xi(i1,3))*(xi(i1,1)-xi(i1,2)+xi(i1,3)-2.)+(1.+xi(i1,1))*(1.-xi(i1,2))*(1.+xi(i1,3)))/8.;
                dNdxi(3*i1-1,6) = (-(1.+xi(i1,1))*(1.+xi(i1,3))*(xi(i1,1)-xi(i1,2)+xi(i1,3)-2.)-(1.+xi(i1,1))*(1.-xi(i1,2))*(1.+xi(i1,3)))/8.;
                dNdxi(3*i1,6) = ((1.+xi(i1,1))*(1.-xi(i1,2))*(xi(i1,1)-xi(i1,2)+xi(i1,3)-2.)+(1.+xi(i1,1))*(1.-xi(i1,2))*(1.+xi(i1,3)))/8.;
                dNdxi(3*i1-2,7) = ((1.+xi(i1,2))*(1.+xi(i1,3))*(xi(i1,1)+xi(i1,2)+xi(i1,3)-2.)+(1.+xi(i1,1))*(1.+xi(i1,2))*(1.+xi(i1,3)))/8.;
                dNdxi(3*i1-1,7) = ((1.+xi(i1,1))*(1.+xi(i1,3))*(xi(i1,1)+xi(i1,2)+xi(i1,3)-2.)+(1.+xi(i1,1))*(1.+xi(i1,2))*(1.+xi(i1,3)))/8.;
                dNdxi(3*i1,7) = ((1.+xi(i1,1))*(1.+xi(i1,2))*(xi(i1,1)+xi(i1,2)+xi(i1,3)-2.)+(1.+xi(i1,1))*(1.+xi(i1,2))*(1.+xi(i1,3)))/8.;
                dNdxi(3*i1-2,8) = (-(1.+xi(i1,2))*(1.+xi(i1,3))*(-xi(i1,1)+xi(i1,2)+xi(i1,3)-2.)-(1.-xi(i1,1))*(1.+xi(i1,2))*(1.+xi(i1,3)))/8.;
                dNdxi(3*i1-1,8) = ((1.-xi(i1,1))*(1.+xi(i1,3))*(-xi(i1,1)+xi(i1,2)+xi(i1,3)-2.)+(1.-xi(i1,1))*(1.+xi(i1,2))*(1.+xi(i1,3)))/8.;
                dNdxi(3*i1,8) = ((1.-xi(i1,1))*(1.+xi(i1,2))*(-xi(i1,1)+xi(i1,2)+xi(i1,3)-2.)+(1.-xi(i1,1))*(1.+xi(i1,2))*(1.+xi(i1,3)))/8.;
                dNdxi(3*i1-2,9)  = -2.*xi(i1,1)*(1.-xi(i1,2))*(1.-xi(i1,3))/4.;
                dNdxi(3*i1-1,9)  = -(1.-(double)(pow(xi(i1,1),2)))*(1.-xi(i1,3))/4.;
                dNdxi(3*i1,9)  = -(1.-(double)(pow(xi(i1,1),2)))*(1.-xi(i1,2))/4.;
                dNdxi(3*i1-2,10)  = (1.-(double)(pow(xi(i1,2),2)))*(1.-xi(i1,3))/4.;
                dNdxi(3*i1-1,10)  = -2.*xi(i1,2)*(1.+xi(i1,1))*(1.-xi(i1,3))/4.;
                dNdxi(3*i1,10)  = -(1.-(double)(pow(xi(i1,2),2)))*(1.+xi(i1,1))/4.;
                dNdxi(3*i1-2,11)  = -2.*xi(i1,1)*(1.+xi(i1,2))*(1.-xi(i1,3))/4.;
                dNdxi(3*i1-1,11)  = (1.-(double)(pow(xi(i1,1),2)))*(1.-xi(i1,3))/4.;
                dNdxi(3*i1,11)  = -(1.-(double)(pow(xi(i1,1),2)))*(1.+xi(i1,2))/4.;
                dNdxi(3*i1-2,12)  = -(1.-(double)(pow(xi(i1,2),2)))*(1.-xi(i1,3))/4.;
                dNdxi(3*i1-1,12)  = -2.*xi(i1,2)*(1.-xi(i1,1))*(1.-xi(i1,3))/4.;
                dNdxi(3*i1,12)  = -(1.-(double)(pow(xi(i1,2),2)))*(1.-xi(i1,1))/4.;
                dNdxi(3*i1-2,13)  = -2.*xi(i1,1)*(1.-xi(i1,2))*(1.+xi(i1,3))/4.;
                dNdxi(3*i1-1,13)  = -(1.-(double)(pow(xi(i1,1),2)))*(1.+xi(i1,3))/4.;
                dNdxi(3*i1,13)  = (1.-(double)(pow(xi(i1,1),2)))*(1.-xi(i1,2))/4.;
                dNdxi(3*i1-2,14)  = (1.-(double)(pow(xi(i1,2),2)))*(1.+xi(i1,3))/4.;
                dNdxi(3*i1-1,14)  = -2.*xi(i1,2)*(1.+xi(i1,1))*(1.+xi(i1,3))/4.;
                dNdxi(3*i1,14)  = (1.-(double)(pow(xi(i1,2),2)))*(1.+xi(i1,1))/4.;
                dNdxi(3*i1-2,15)  = -2.*xi(i1,1)*(1.+xi(i1,2))*(1.+xi(i1,3))/4.;
                dNdxi(3*i1-1,15)  =  (1.-(double)(pow(xi(i1,1),2)))*(1.+xi(i1,3))/4.;
                dNdxi(3*i1,15)  = (1.-(double)(pow(xi(i1,1),2)))*(1.+xi(i1,2))/4.;
                dNdxi(3*i1-2,16)  = -(1.-(double)(pow(xi(i1,2),2)))*(1.+xi(i1,3))/4.;
                dNdxi(3*i1-1,16)  = -2.*xi(i1,2)*(1.-xi(i1,1))*(1.+xi(i1,3))/4.;
                dNdxi(3*i1,16)  = (1.-(double)(pow(xi(i1,2),2)))*(1.-xi(i1,1))/4.;
                dNdxi(3*i1-2,17) = -(1.-xi(i1,2))*(1.-(double)(pow(xi(i1,3),2)))/4.;
                dNdxi(3*i1-1,17) = -(1.-xi(i1,1))*(1.-(double)(pow(xi(i1,3),2)))/4.;
                dNdxi(3*i1,17) = -xi(i1,3)*(1.-xi(i1,1))*(1.-xi(i1,2))/2.;
                dNdxi(3*i1-2,18) = (1.-xi(i1,2))*(1.-(double)(pow(xi(i1,3),2)))/4.;
                dNdxi(3*i1-1,18) = -(1.+xi(i1,1))*(1.-(double)(pow(xi(i1,3),2)))/4.;
                dNdxi(3*i1,18) = -xi(i1,3)*(1.+xi(i1,1))*(1.-xi(i1,2))/2.;
                dNdxi(3*i1-2,19) = (1.+xi(i1,2))*(1.-(double)(pow(xi(i1,3),2)))/4.;
                dNdxi(3*i1-1,19) = (1.+xi(i1,1))*(1.-(double)(pow(xi(i1,3),2)))/4.;
                dNdxi(3*i1,19) = -xi(i1,3)*(1.+xi(i1,1))*(1.+xi(i1,2))/2.;
                dNdxi(3*i1-2,20) = -(1.+xi(i1,2))*(1.-(double)(pow(xi(i1,3),2)))/4.;
                dNdxi(3*i1-1,20) = (1.-xi(i1,1))*(1.-(double)(pow(xi(i1,3),2)))/4.;
                dNdxi(3*i1,20) = -xi(i1,3)*(1.-xi(i1,1))*(1.+xi(i1,2))/2.;
            }
            break;
        }
            
        case 10:{
            
            for(int i1=1;i1<=pp(1);i1++)
            {
                double xi5 = 1.-xi(i1,1)-xi(i1,2)-xi(i1,3);
                dNdxi(3*i1-2,1) = (4.*xi(i1,1)-1.);
                dNdxi(3*i1-1,2) = (4.*xi(i1,2)-1.);
                dNdxi(3*i1,3) = (4.*xi(i1,3)-1.);
                dNdxi(3*i1-2,4) = -(4.*xi5-1.);
                dNdxi(3*i1-1,4) = -(4.*xi5-1.);
                dNdxi(3*i1,4) = -(4.*xi5-1.);
                dNdxi(3*i1-2,5) = 4.*xi(i1,2);
                dNdxi(3*i1-1,5) = 4.*xi(i1,1);
                dNdxi(3*i1-1,6) = 4.*xi(i1,3);
                dNdxi(3*i1,6) = 4.*xi(i1,2);
                dNdxi(3*i1-2,7) = 4.*xi(i1,3);
                dNdxi(3*i1,7) = 4.*xi(i1,1);
                dNdxi(3*i1-2,8) = 4.-4.*xi(i1,2)-8.*xi(i1,1)-4.*xi(i1,3);
                dNdxi(3*i1-1,8) = -4.*xi(i1,1);
                dNdxi(3*i1,8) = -4.*xi(i1,1);
                dNdxi(3*i1-2,9) = -4.*xi(i1,2);
                dNdxi(3*i1-1,9) = 4.-4.*xi(i1,1)-8.*xi(i1,2)-4.*xi(i1,3);
                dNdxi(3*i1,9) = -4.*xi(i1,2);
                dNdxi(3*i1-2,10) = -4.*xi(i1,3);
                dNdxi(3*i1-1,10) = -4.*xi(i1,3);
                dNdxi(3*i1,10) = 4.*(xi5-xi(i1,3));
            }
            
            break;
        }
        default:
        {
            cout<<"No such case for defining shape function"<<endl;
            break;
        }
    }
    
    
    
    
    
    return dNdxi;
    
}





#endif /* shapeFunction_h */
