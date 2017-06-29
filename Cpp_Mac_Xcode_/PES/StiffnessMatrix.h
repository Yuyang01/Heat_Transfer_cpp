//
//  StiffnessMatrix.h
//  PES
//
//  Created by Yuyang Wang on 16/5/1.
//  Copyright © 2016年 Yuyang Wang. All rights reserved.
//

#ifndef StiffnessMatrix_h
#define StiffnessMatrix_h
#include"Matrix.hpp"
#include"Vector.hpp"
#include "EleStiffness.h"
using namespace std;


void Stiff(Matrix& K,Vector& f,Matrix& X,Matrix& T,Matrix& N,Matrix& dN,Matrix& xi,Vector& w,Vector& pp)
{
    //allocate storage for stiffness matrix
    Matrix kk(int(pp(4)),int(pp(4)));
    
    
    //loop on elements
    for(int ielem=1;ielem<=pp(5);ielem++)
    {
       //Te :global number of the nodes in the current element
        //Xe: coordinates of the nodes in the current element
        Vector Te((int)pp(3));
        for(int i=2;i<=T.GetNumberOfColumns();i++)
        {
            Te(i-1)=T(ielem,i);
        }
        
        
        //get local information
        Matrix Xe(pp(3),pp(2));
        for(int i=1;i<=(int)pp(3);i++)
        {
            for(int j=1;j<=pp(2);j++)
            {
                Xe(i,j)=X(Te(i),j+1);
               // cout<<"Xe="<<Xe(i,j)<<endl;
            }
        }
        
        //element matrices
        Matrix Ke((int)pp(3),(int)pp(3));
        Matrix fe((int)pp(3),1);
        MatEl(Ke,fe,Xe,xi,N,dN,w,pp);
     // cout<<"Ke1 from stiffnessMatrix= "<<Ke(1,1)<<"  ke2="<<Ke(2,1)<<endl;
        //cout<<"pp2="<<pp(2)<<endl;
        //assemble the element matrix
        for(int i=1;i<=pp(3);i++)
        {
            for(int j=1;j<=pp(3);j++)
            {
                K(Te(i),Te(j))=K(Te(i),Te(j))+Ke(i,j);
            }
            f(Te(i))=f(Te(i))+fe(i,1);
        }
        
        
        
    }
    

}



#endif // StiffnessMatrix_h
 
