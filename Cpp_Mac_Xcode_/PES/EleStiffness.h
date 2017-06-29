//
//  EleStiffness.h
//  PES
//
//  Created by Yuyang Wang on 16/5/1.
//  Copyright © 2016年 Yuyang Wang. All rights reserved.
//

#ifndef EleStiffness_h
#define EleStiffness_h
#include "Matrix.hpp"
#include "Vector.hpp"
#include "MatrixInverse.h"
double SourceTerm(Vector& aux);
void MatEl(Matrix& Ke,Matrix & fe,Matrix& Xe,Matrix& xi,Matrix& N,Matrix& dN,Vector& w,Vector& pp)
{
    
    if(pp(2)==2) // in 2d
    {
   
    //loop on Gauss points (computation of integrals on the current element)
    for(int i=1;i<=pp(1);i++)
    {
        Vector N_igaus(N.GetNumberOfColumns());
        for(int j=1;j<=N.GetNumberOfColumns();j++)
        {
            N_igaus(j)=N(i,j);
        }
        
        Vector Nxi_igaus(dN.GetNumberOfColumns());
        Vector Neta_igaus(dN.GetNumberOfColumns());
        for(int j=1;j<=dN.GetNumberOfColumns();j++)
        {
            Nxi_igaus(j)=dN(2*i-1,j);
           // cout<<"Nxi_igaus="<<Nxi_igaus(j)<<endl;
            
            Neta_igaus(j)=dN(2*i,j);
           // Ngamma_igaus(j)=
            
        }
        
        Matrix Jacob((int)pp(2),(int)pp(2));
        Vector a=Nxi_igaus*Xe;
        Vector b=Neta_igaus*Xe;
     //   Vector c= Ngamma_igaus*Xe
        for(int j=1;j<=pp(2);j++)
        {
            for(int k=1;k<=pp(2);k++)
            {
                if(j==1)
                {
                    Jacob(j,k)=a(k);
                }
                else if(j==2)
                {
                    Jacob(j,k)=b(k);
                }
            }
            
        }
        
       double dvolu=w(i)*Jacob.CalculateDeterminant();
      // cout<<"dvolu= "<<w(i)<<endl;
        
        Matrix invJacob=Inverse(Jacob);
        Matrix temp((int)pp(2),(int)pp(3));
        
        for(int j=1;j<=pp(2);j++)
        {
            for(int k=1;k<=pp(3);k++)
            {
                if(j==1)
                {
                    temp(j,k)=Nxi_igaus(k);
                }
                else if(j==2)
                {
                    temp(j,k)=Neta_igaus(k);
                }
                // else if(j==3)
                // {
                // temp(j,k)=Ngamma_igaus(k);
                // }
            }
        }

    
        Matrix res=invJacob*temp;
       // cout<<"  res11 "<<res(1,1)<<"  "<<res(1,2)<<"  "<<res(1,3)<<"  "<<res(1,4)<<endl;
        Matrix Nx_row((int)pp(3),1);
        Matrix Nx_col(1,(int)pp(3));
        
        Matrix Ny_row((int)pp(3),1);
        Matrix Ny_col(1,(int)pp(3));
        
  
        
        for(int j=1;j<=pp(3);j++)
        {
            Nx_row(j,1)=res(1,j);
            Nx_col(1,j)=res(1,j);
            Ny_row(j,1)=res(2,j);
            Ny_col(1,j)=res(2,j);
            
         
            
            
        }
       // cout<<"  Ny11: "<<Ny_col(1,1)<<"  "<<Ny_col(1,2)<<"  "<<Ny_col(1,3)<<"  "<<Ny_col(1,4)<<endl;
//until here it is true
        
        Matrix Nx=(Nx_row*Nx_col)*pp(6);
        Matrix Ny=(Ny_row*Ny_col)*pp(6);
        
        
        // obtain local stiffness matrix Ke
      // cout<<"Ke before calculation="<<Ke(1,1)<<"  "<<Ke(1,2)<<"  "<<Ke(1,3)<<endl;
        Ke = Ke + ((Nx+Ny)*dvolu);
     //  cout<<"Ke after calculation="<<Ke(1,1)<<"  "<<Ke(1,2)<<"  "<<Ke(1,3)<<endl;

        
        
        
        //Continue to work for local source vector
        Vector aux=N_igaus*Xe;
        double f_igaus=SourceTerm(aux);
        Matrix N_igausTranspose((int)pp(3),1);
        for(int j=1;j<=pp(3);j++)
        {
            N_igausTranspose(j,1)=N_igaus(j);
        }
        
        fe=fe+N_igausTranspose*(f_igaus*dvolu);
        
    }
   
        
    }
    
    ////////////////////////////////////////////////////////////////////////////////
    else //in 3d
    {
        
        //loop on Gauss points (computation of integrals on the current element)
        for(int i=1;i<=pp(1);i++)
        {
            Vector N_igaus(N.GetNumberOfColumns());
            for(int j=1;j<=N.GetNumberOfColumns();j++)
            {
                N_igaus(j)=N(i,j);
            }
            
            Vector Nxi_igaus(dN.GetNumberOfColumns());
            Vector Neta_igaus(dN.GetNumberOfColumns());
            Vector Ngamma_igaus(dN.GetNumberOfColumns());
            for(int j=1;j<=dN.GetNumberOfColumns();j++)
            {
                Nxi_igaus(j)=dN(3*i-2,j);
                
                Neta_igaus(j)=dN(3*i-1,j);
                Ngamma_igaus(j)=dN(3*i,j);
                
            }
            
            Matrix Jacob((int)pp(2),(int)pp(2));
            Vector a=Nxi_igaus*Xe;
            Vector b=Neta_igaus*Xe;
            Vector c= Ngamma_igaus*Xe;
            
            for(int j=1;j<=pp(2);j++)
            {
                for(int k=1;k<=pp(2);k++)
                {
                    if(j==1)
                    {
                        Jacob(j,k)=a(k);
                    }
                    else if(j==2)
                    {
                        Jacob(j,k)=b(k);
                    }
                    else if(j==3)
                    {
                    Jacob(j,k)=c(k);
                    }
                    
                }
                
            }
            
            double dvolu=w(i)*Jacob.CalculateDeterminant();
            // cout<<"dvolu= "<<dvolu<<endl;
            
            Matrix invJacob=Inverse(Jacob);
            Matrix temp((int)pp(2),(int)pp(3));
            
            for(int j=1;j<=pp(2);j++)
            {
                for(int k=1;k<=pp(3);k++)
                {
                    if(j==1)
                    {
                        temp(j,k)=Nxi_igaus(k);
                    }
                    else if(j==2)
                    {
                        temp(j,k)=Neta_igaus(k);
                    }
                     else if(j==3)
                     {
                     temp(j,k)=Ngamma_igaus(k);
                     }
                }
            }
            
            
            Matrix res=invJacob*temp;
            // cout<<"  res11 "<<res(1,1)<<"  "<<res(1,2)<<"  "<<res(1,3)<<"  "<<res(1,4)<<endl;
            Matrix Nx_row((int)pp(3),1);
            Matrix Nx_col(1,(int)pp(3));
            
            Matrix Ny_row((int)pp(3),1);
            Matrix Ny_col(1,(int)pp(3));
            
             Matrix Nz_row((int)pp(3),1);
             Matrix Nz_col(1,(int)pp(3));
            
            for(int j=1;j<=pp(3);j++)
            {
                Nx_row(j,1)=res(1,j);
                Nx_col(1,j)=res(1,j);
                Ny_row(j,1)=res(2,j);
                Ny_col(1,j)=res(2,j);
                
                 Nz_row(j,1)=res(3,j);
                 Nz_col(1,j)=res(3,j);
                
                
            }
            //cout<<"  Ny11: "<<Ny_col(1,1)<<"  "<<Ny_col(1,2)<<"  "<<Ny_col(1,3)<<"  "<<Ny_col(1,4)<<endl;
            //until here it is true
            
            Matrix Nx=(Nx_row*Nx_col)*pp(6);
            Matrix Ny=(Ny_row*Ny_col)*pp(6);
            Matrix Nz=(Nz_row*Nz_col)*pp(6);
            
            // obtain local stiffness matrix Ke
            // cout<<"Ke before calculation="<<Ke(1,1)<<"  "<<Ke(1,2)<<"  "<<Ke(1,3)<<endl;
            Ke = Ke + ((Nx+Ny)*dvolu);
            //  cout<<"Ke after calculation="<<Ke(1,1)<<"  "<<Ke(1,2)<<"  "<<Ke(1,3)<<endl;
            
            
            
            
            //Continue to work for local source vector
            Vector aux=N_igaus*Xe;
            double f_igaus=SourceTerm(aux);
            Matrix N_igausTranspose((int)pp(3),1);
            for(int j=1;j<=pp(3);j++)
            {
                N_igausTranspose(j,1)=N_igaus(j);
            }
            
            fe=fe+N_igausTranspose*(f_igaus*dvolu);
  
        
    }
    }
        
}








double SourceTerm(Vector& aux)
{
    
    double f_igaus=0;
    
    return f_igaus;
    
}

#endif /* EleStiffness_h */
