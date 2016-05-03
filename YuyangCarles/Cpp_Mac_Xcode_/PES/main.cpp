//
//  main.cpp
//  PES
//
//  Created by Yuyang Wang on 16/4/30.
//  Copyright © 2016年 Yuyang Wang. All rights reserved.
//

#include<iostream>
#include"postprocess.h"
#include"Vector.hpp"
#include"Matrix.hpp"
#include "Parameter.h"
#include "Integration.h"
#include "shapeFunction.h"
#include "StiffnessMatrix.h"
#include "MatrixInverse.h"
#include "SolveEq.h"
#include<fstream>
#include<sstream>
#include <ctime>

using namespace std;

int main(){
    
    // Section 1
    // Start ask the user to input the data:
    //-Connectivity matrix
    //-Node coordinate
    //-Inlet boundary condition
    //-Outlet boundary condition
    
    cout<<"This program solves a Possion equation :"<<endl;
    
    
    char filename1[256];
    cout<<"Please,input the file name for Connectivity Matrix:"<<endl;
    cin>>filename1;
    
    char filename2[256];
    cout<<"Please,input the file name for Nodes Coordinates:"<<endl;
    cin>>filename2;
    
    char filename3[256];
    cout<<"Please,input the file name for Inlet Boundary Condition:"<<endl;
    cin>>filename3;
    
    char filename4[256];
    cout<<"Please,input the file name for Outlet Boundary Condition:"<<endl;
    cin>>filename4;
    
    clock_t start,ends;
    start =clock();
    
    
    Matrix T(filename1);
   // cout<<"reading t="<<endl;
    
        Matrix X(filename2);
   // cout<<"reading x="<<endl;

   // cout<<"reading in="<<endl;
    Matrix In(filename3);
   // cout<<"reading out="<<endl;
    Matrix Out(filename4);
    
    // End read data. Objects have been set.
    
    
    

    
    
//define a function to return:1 #gauss point, 2#coordinates, 3#nodes for each element,4 #points, 5#elements
    Vector pp=data(X,T);
    
    //definition of weighting for gauss integration
    Vector w=weight(X,T,pp);
    
    //definiton of gauss point
    Matrix xi=shape_xi(X, T,pp);
    
    //definition of shape function
    Matrix N=shape_N(X,T,xi,pp);
    
    //definition of the derivative of shape function
    Matrix dN=shape_dN(X,T,xi,pp);
    
    //create the global stiffness matrix
    Matrix K((int)(pp(4)),(int)(pp(4)));
   
    
    //create the global source vector
    Vector f((int)(pp(4)));
    
    
    //compute the global stiffness matrix, glbal source vector
    Stiff(K,f,X,T,N,dN,xi,w,pp);


    
 //Until now we have obtained "stiffness matrix" and "source vector"
  // Continue to consider the Dirichlet boundary condition
    // Create Bundary condition matrix,
  
    //solve equation by lagrange multipliers
   Vector temp= solve_eq(K,f,X,T,In,Out);
   Vector solution(length(f));
    for(int i=1;i<=length(f);i++)
    {
        solution(i)=temp(i);
    }
    
    
    
    //start post process
    post(X,T,solution);
    
    ends=clock();
    double diff=(ends-start)/double(CLOCKS_PER_SEC);
    cout<<"Total time for the problem="<<diff<<"\n"<<endl;
    cout<<"End Program!\n"<<endl;
    cout<<"Thanks!\n"<<endl;
    return 0;
}
