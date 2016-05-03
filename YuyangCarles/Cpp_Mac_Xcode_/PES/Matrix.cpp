//
//  Matrix.cpp
//  PES
//
//  Created by Yuyang Wang on 16/4/30.
//  Copyright © 2016年 Yuyang Wang. All rights reserved.
//
#include <cmath>
#include <cassert>

#include <sstream>
#include <iostream>
#include <vector>
#include<fstream>
#include<string>


#include "Matrix.hpp"
#include "Vector.hpp"
using namespace std;

Matrix::Matrix()
{
//    mNumCols=3;
//    mNumRows=3;
//    mData = new double* [mNumRows];
//    
//    for (int i=0; i<mNumRows; i++)
//    {
//        mData[i] = new double [mNumCols];
//    }
//    
//    for (int i=0; i<mNumRows; i++)
//    {
//        for (int j=0; j<mNumCols; j++)
//        {
//            mData[i][j]=0.0;
//        }
//    }
    
}


// Overwritten copy constructor
// Allocate memory for new matrix, and copy
// entries into this matrix
Matrix::Matrix(const Matrix& otherMatrix)
{
    mNumRows = otherMatrix.mNumRows;
    mNumCols = otherMatrix.mNumCols;
    mData = new double* [mNumRows];
    for (int i=0; i<mNumRows; i++)
    {
        mData[i] = new double [mNumCols];
    }
    
    for (int i=0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
}

// Constructor for vector of a given length
// Allocates memory, and initialises entries
// to zero
Matrix::Matrix(int numRows, int numCols)
{
    assert(numRows > 0);
    assert(numCols > 0);
    mNumRows = numRows;
    mNumCols = numCols;
    mData = new double* [mNumRows];
    for (int i=0; i<mNumRows; i++)
    {
        mData[i] = new double [mNumCols];
    }
    for (int i=0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            mData[i][j] = 0.0;
        }
    }
}


Matrix::Matrix(char* filename){
    
    mNumRows = 0;
    mNumCols = 0;
    
    ifstream file;
    file.open(filename,ios::in);
    if(file.fail())
    {
        cout<<"Fail to open"<<filename<<endl;
    }
    else
    {
        string temp1;
        while(getline(file,temp1))
        {
            mNumRows++;// after iteration, we obtain the rows of the input matrix
        }
        vector<string> strings;
        istringstream f(temp1);
        string s;
        while(getline(f,s,','))
        {
            strings.push_back(s);
        }
        mNumCols = (int)(strings.size());// we obtain the cols of the input matrix
    }
    file.close();
    
    //start to write the entry of file, save it in  a matrix
    file.open(filename,ios::in);
    mData = new double* [mNumRows];
    for (int i=0; i<mNumRows; i++)
    {
        mData[i] = new double [mNumCols];
    }
    
    int i=1;
    string temp2;
    while(getline(file,temp2)){
        vector<double> number;
        istringstream f(temp2);
        string s;
        while(getline(f,s,',')){
            number.push_back(atof(s.c_str()));
        }
        vector<double>:: const_iterator c;
        int j=0;
        for(c=number.begin();c!=number.end();c++){
            mData[i-1][j]=*c;
            j++;
        }
        i++;
    }
    file.close();
    
}



// Overwritten destructor to correctly free memory
Matrix::~Matrix()
{
    for (int i=0; i<mNumRows; i++)
    {
        delete[] mData[i];
    }
    delete[] mData;
   // cout<<"Destructor for class 'Matrix'"<<endl;
}

// Method to get number of rows of matrix
int Matrix::GetNumberOfRows() const
{
    return mNumRows;
}

// Method to get number of columns of matrix
int Matrix::GetNumberOfColumns() const
{
    return mNumCols;
}

// Overloading the round brackets
// Note that this uses `one-based' indexing,
// and a check on the validity of the index
double& Matrix::operator()(int i, int j)
{
    assert(i > 0);
    assert(i < mNumRows+1);
    assert(j > 0);
   assert(j < mNumCols+1);
    return mData[i-1][j-1];
}

// Overloading the assignment operator
Matrix& Matrix::operator=(const Matrix& otherMatrix)
{
    assert(mNumRows = otherMatrix.mNumRows);
    assert(mNumCols = otherMatrix.mNumCols);
    
    for (int i=0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
    return *this;
}

// Overloading the unary + operator
Matrix Matrix::operator+() const
{
    Matrix mat(mNumRows, mNumCols);
    for (int i=0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            mat(i+1,j+1) = mData[i][j];
        }
    }
    return mat;
}

// Overloading the unary - operator
Matrix Matrix::operator-() const
{
    Matrix mat(mNumRows, mNumCols);
    for (int i=0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            mat(i+1,j+1) = -mData[i][j];
        }
    }
    return mat;
}

// Overloading the binary + operator
Matrix Matrix::operator+(const Matrix& m1) const
{
    assert(mNumRows == m1.mNumRows);
    assert(mNumCols == m1.mNumCols);
    Matrix mat(mNumRows, mNumCols);
    for (int i=0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            mat(i+1,j+1) = mData[i][j] + m1.mData[i][j];
        }
    }
    return mat;
}

// Overloading the binary - operator
Matrix Matrix::operator-(const Matrix& m1) const
{
    assert(mNumRows == m1.mNumRows);
    assert(mNumCols == m1.mNumCols);
    Matrix mat(mNumRows, mNumCols);
    for (int i=0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            mat(i+1,j+1) = mData[i][j] - m1.mData[i][j];
        }
    }
    return mat;
}

// Overloading scalar multiplication
Matrix Matrix::operator*(double a) const
{
    Matrix mat(mNumRows, mNumCols);
    for (int i=0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            mat(i+1,j+1) = a*mData[i][j];
        }
    }
    return mat;
}

// Overloading matrix multiplied by a vector
Vector operator*(const Matrix& m, const Vector& v)
{
    int original_vector_size = v.GetSize();
    assert(m.GetNumberOfColumns() == original_vector_size);
    int new_vector_length = m.GetNumberOfRows();
    Vector new_vector(new_vector_length);
    
    for (int i=0; i<new_vector_length; i++)
    {
        for (int j=0; j<original_vector_size; j++)
        {
            new_vector[i] += m.mData[i][j]*v.Read(j);
        }
    }
    
    return new_vector;
}

// Overloading vector multiplied by a matrix
Vector operator*(const Vector& v, const Matrix& m)
{
    int original_vector_size = v.GetSize();
    assert(m.GetNumberOfRows() == original_vector_size);
    int new_vector_length = m.GetNumberOfColumns();
    Vector new_vector(new_vector_length);
    
    for (int i=0; i<new_vector_length; i++)
    {
        for (int j=0; j<original_vector_size; j++)
        {
            new_vector[i] += v.Read(j)*m.mData[j][i];
        }
    }
    
    return new_vector;
}


Matrix operator*(const Matrix& m,const Matrix& v)
{
    assert(m.GetNumberOfColumns()==v.GetNumberOfRows());
    int rows=m.GetNumberOfRows();
    int cols=v.GetNumberOfColumns();
    
    Matrix mat(rows,cols);
    
    for(int i=1;i<=rows;i++)
    {
        for(int j=1;j<=cols;j++)
        {
         //compute mat(i,j)
            for(int p=1;p<=m.GetNumberOfColumns();p++)
            {
               // mat(i,j)+=m(i,p)*v(p,j);
                mat.mData[i-1][j-1]+=m.mData[i-1][p-1]*v.mData[p-1][j-1];
                
            }
        }
    }
    
    return mat;
    
}







// Calculate determinant of square matrix recursively
double Matrix::CalculateDeterminant() const
{
    assert(mNumRows == mNumCols);
    double determinant = 0.0;
    
    if (mNumRows == 1)
    {
        determinant = mData[0][0];
    }
    else
    {
        // More than one entry of matrix
        for (int i_outer=0; i_outer<mNumRows; i_outer++)
        {
            Matrix sub_matrix(mNumRows-1,
                              mNumRows-1);
            for (int i=0; i<mNumRows-1; i++)
            {
                for (int j=0; j<i_outer; j++)
                {
                    sub_matrix(i+1,j+1) = mData[i+1][j];
                }
                for (int j=i_outer; j<mNumRows-1; j++)
                {
                    sub_matrix(i+1,j+1) = mData[i+1][j+1];
                }
            }
            double sub_matrix_determinant =
            sub_matrix.CalculateDeterminant();
            
            determinant += pow(-1.0, i_outer)*
            mData[0][i_outer]*sub_matrix_determinant;
        }
    }
    return determinant;
}


// compute the trace of the matrix
double Matrix::Trace() const

{
    assert(mNumRows==mNumCols);
    double trace=0;
    for(int i=0;i<mNumRows;i++)
    {
        trace+=mData[i][i];
    }
    
    
    
    return trace;
}



//
