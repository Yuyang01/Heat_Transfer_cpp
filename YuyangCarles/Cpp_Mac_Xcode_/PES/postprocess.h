//
//  postprocess.h
//  PES
//
//  Created by Yuyang Wang on 16/4/30.
//  Copyright © 2016年 Yuyang Wang. All rights reserved.
//

#ifndef postprocess_h
#define postprocess_h
#include<iomanip>
#include<fstream>
#include<sstream>
#include "Matrix.hpp"
using namespace std;
void post(Matrix& X,Matrix &T,Vector& sol)
{
    int EleNodes= T.GetNumberOfColumns()-1;
    double a=0;
    ofstream file;
    file.open("Paraview.vtk");
    file<<"# vtk DataFile Version 1.0"<<"\n";
    file<<"ECM-CELL DIFFUSION-MECHANICS"<<"\n";
    file<<"ASCII\n"<<"\n";
    file<<"DATASET UNSTRUCTURED_GRID"<<"\n";
    file<<"POINTS      "<<X.GetNumberOfRows()<<" float"<<endl;
    //write coordinate to file
    if(X.GetNumberOfColumns()==3){
        
        for(int i=1; i<=X.GetNumberOfRows(); i++) {
            for(int j=2; j<=X.GetNumberOfColumns(); j++) {
                
                file<<std::setiosflags(ios::scientific)<<std::setprecision(8)<<X(i,j)<<" ";
            }
            file<<std::setiosflags(ios::scientific)<<std::setprecision(8)<<a<<endl;
        }
    }
    else
    {
        
        for(int i=1; i<=X.GetNumberOfRows(); i++) {
            for(int j=2; j<=X.GetNumberOfColumns(); j++) {

                file<<std::setiosflags(ios::scientific)<<std::setprecision(8)<<X(i,j)<<"\n ";
            }
        }
    }
   
    
    
    
    //write connectivity matrix to file
    switch(EleNodes){
        case 4:
        {
            file<<"\n";
            if(X.GetNumberOfColumns()==3){
                file<<setw(1)<<"CELLS"<<setw(6)<<T.GetNumberOfRows()<<setw(12)<<T.GetNumberOfRows()*5<<endl;
                
                for(int i=1; i<=T.GetNumberOfRows(); i++) {
                    for(int j=2; j<=T.GetNumberOfColumns(); j++) {
                        
                        if(j==2){
                            file<<4<<"  "<<(int)(T(i,j)-1)<<"  ";
                        }
                        else
                        {
                            file<<(int)(T(i,j)-1)<<" ";
                        }
                    }
                    file<<endl;
                }
                file<<"\n";
                file<<setw(1)<<"CELL_TYPES"<<setw(6)<<T.GetNumberOfRows()<<"\n";
                for(int i=1;i<=T.GetNumberOfRows();i++){
                    file<<9<<"     ";
                }
            }
            else{
                
                file<<setw(1)<<"CELLS"<<setw(6)<<T.GetNumberOfRows()<<setw(12)<<T.GetNumberOfRows()*5<<endl;
                for(int i=1; i<=T.GetNumberOfRows(); i++) {
                    for(int j=2; j<=T.GetNumberOfColumns(); j++) {
                        if(j==2){
                            file<<4<<"  "<<(int)(T(i,j)-1)<<"  ";
                        }
                        else
                        {
                            file<<(int)(T(i,j)-1)<<" ";
                        }
                    }
                    file<<endl;
                }
                file<<"\n";
                file<<setw(1)<<"CELL_TYPES"<<setw(6)<<T.GetNumberOfRows()<<"\n";
                for(int i=1;i<=T.GetNumberOfRows();i++){
                    file<<10<<"     ";
                }
                
            }
            
            break;
        }//end case 4
        case 8:
        {
            if(X.GetNumberOfColumns()==3){
                file<<setw(1)<<"CELLS"<<setw(6)<<T.GetNumberOfRows()<<setw(12)<<T.GetNumberOfRows()*9<<endl;
                for(int i=1; i<=T.GetNumberOfRows(); i++) {
                    for(int j=2; j<=T.GetNumberOfColumns(); j++) {
                        if(j==2){
                            file<<8<<"  "<<(int)(T(i,j)-1)<<"  ";
                        }
                        else
                        {
                            file<<(int)(T(i,j)-1)<<" ";
                        }
                    }
                    file<<endl;
                }
                file<<"\n";
                file<<setw(1)<<"CELL_TYPES"<<setw(6)<<T.GetNumberOfRows()<<"\n";
                for(int i=1;i<=T.GetNumberOfRows();i++){
                    file<<23<<"     ";
                }
            }
            
            else {
                file<<setw(1)<<"CELLS"<<setw(6)<<T.GetNumberOfRows()<<setw(12)<<T.GetNumberOfRows()*9<<endl;
                for(int i=1; i<=T.GetNumberOfRows(); i++) {
                    for(int j=2; j<=T.GetNumberOfColumns(); j++) {
                        if(j==2){
                            file<<8<<"  "<<(int)(T(i,j)-1)<<"  ";
                        }
                        else
                        {
                            file<<(int)(T(i,j)-1)<<" ";
                        }
                    }
                    file<<endl;
                }
                file<<"\n";
                file<<setw(1)<<"CELL_TYPES"<<setw(6)<<T.GetNumberOfRows()<<"\n";
                for(int i=1;i<=T.GetNumberOfRows();i++){
                    file<<12<<"     ";
                }
            }
            
            break;
        }//end case 8
        case 3:
        {
            
            
            file<<setw(1)<<"CELLS"<<setw(6)<<T.GetNumberOfRows()<<setw(12)<<T.GetNumberOfRows()*4<<endl;
            for(int i=1; i<=T.GetNumberOfRows(); i++) {
                for(int j=2; j<=T.GetNumberOfColumns(); j++) {
                    if(j==2){
                        file<<3<<"  "<<(int)(T(i,j)-1)<<"  ";
                    }
                    else
                    {
                        file<<(int)(T(i,j)-1)<<" ";
                    }
                }
                file<<endl;
            }
            file<<"\n";
            file<<setw(1)<<"CELL_TYPES"<<setw(6)<<T.GetNumberOfRows()<<"\n";
            for(int i=1;i<=T.GetNumberOfRows();i++){
                file<<5<<"     ";
            }
        }//end case 3
            
            
        case 6:
            
        {
            file<<setw(1)<<"CELLS"<<setw(6)<<T.GetNumberOfRows()<<setw(12)<<T.GetNumberOfRows()*7<<endl;
            for(int i=1; i<=T.GetNumberOfRows(); i++) {
                for(int j=2; j<=T.GetNumberOfColumns(); j++) {
                    if(j==2){
                        file<<6<<"  "<<(int)(T(i,j)-1)<<"  ";
                    }
                    else
                    {
                        file<<(int)(T(i,j)-1)<<" ";
                    }
                }
                file<<endl;
            }
            file<<"\n";
            file<<setw(1)<<"CELL_TYPES"<<setw(6)<<T.GetNumberOfRows()<<"\n";
            for(int i=1;i<=T.GetNumberOfRows();i++){
                file<<22<<"     ";
            }
        
            
            break; }//end case 6
        case 20:
        {
            file<<setw(1)<<"CELLS"<<setw(6)<<T.GetNumberOfRows()<<setw(12)<<T.GetNumberOfRows()*21<<endl;
            for(int i=1; i<=T.GetNumberOfRows(); i++) {
                for(int j=2; j<=T.GetNumberOfColumns(); j++) {
                    if(j==2){
                        file<<20<<"  "<<(int)(T(i,j)-1)<<"  ";
                    }
                    else
                    {
                        file<<(int)(T(i,j)-1)<<" ";
                    }
                }
                file<<endl;
            }
            file<<"\n";
            file<<setw(1)<<"CELL_TYPES"<<setw(6)<<T.GetNumberOfRows()<<"\n";
            for(int i=1;i<=T.GetNumberOfRows();i++){
                file<<25<<"     ";
            }
            
            break;
         
        }
        case 10:
            
        {
            
            
            file<<setw(1)<<"CELLS"<<setw(6)<<T.GetNumberOfRows()<<setw(12)<<T.GetNumberOfRows()*11<<endl;
            for(int i=1; i<=T.GetNumberOfRows(); i++) {
                for(int j=2; j<=T.GetNumberOfColumns(); j++) {
                    if(j==2){
                        file<<10<<"  "<<(int)(T(i,j)-1)<<"  ";
                    }
                    else
                    {
                        file<<(int)(T(i,j)-1)<<" ";
                    }
                }
                file<<endl;
            }
            file<<"\n";
            file<<setw(1)<<"CELL_TYPES"<<setw(6)<<T.GetNumberOfRows()<<"\n";
            for(int i=1;i<=T.GetNumberOfRows();i++){
                file<<24<<"     ";
            }
            
            break;
        }
            
        default:
        {
            std::cout<<"No such case for postprocess"<<"\n";
            
        }
    }
    
    
    file<<"\n";
    //write variables
    file<<"POINT_DATA      "<<X.GetNumberOfRows()<<"\n";
    file<<"SCALARS Ux float"<<"\n";
    file<<"LOOKUP_TABLE default"<<"\n";
    
    //write solutions
    for(int i=1; i<=X.GetNumberOfRows(); i++) {
        file<<std::setiosflags(ios::scientific)<<std::setprecision(8)<<sol(i)<<"\n";
    }
    
    
    file.close();
    
}

#endif /* postprocess_h */
