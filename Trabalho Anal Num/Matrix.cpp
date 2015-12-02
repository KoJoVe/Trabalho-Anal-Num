//
//  Matriz.c
//  AnaliseNumerica
//
//  Created by Gabriel Coutinho de Paula on 8/12/15.
//  Copyright (c) 2015 Gabriel Coutinho de Paula. All rights reserved.
//

#include <stdio.h>

#include "Matrix.hpp"

double** Matrix::newMatrix (size_t m, size_t n)
{
    double** matrix = new double*[m];
    
    for (int i = 0; i < m; i++)
    {
        double* b = new double[n];
        matrix[i] = b;
    }
    return matrix;
}

void Matrix::deleteMatrix (size_t m, double** A)
{
    for (int i = 0; i < m; i++)
    {
        delete A[i];
    }
    
    delete A;
}

void Matrix::transpose (size_t m, size_t n, double** A, double** T)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            T[j][i] = A[i][j];
        }
    }
}

void Matrix::multWithArray (size_t m, size_t n, double** A, double* v, double* w)
{
    for (int i = 0; i < m; i++)
    {
        w[i] = 0.0;
        
        for (int j = 0; j < n; j++)
        {
            w[i] += A[i][j]*v[j];
        }
    }
}

void Matrix::mult (size_t m, size_t n, size_t q, double** A, double ** B, double** C)
{
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < q; k++)
        {
            C[i][k] = 0.0;
            
            for (int j = 0; j < n; j++)
            {
                C[i][k] += A[i][j]*B[j][k];
            }
        }
    }
}




//
double** Matrix::squareIdentity(size_t m)
{
    double** identity = newMatrix(m, m);
    
    zera(m, m, identity);
    
    for (int i = 0; i < m; i++)
    {
        identity[i][i] = 1.0;
    }
        
    return identity;
}

void Matrix::printaM (size_t m, size_t n, double** A)
{
    printf("BEGIN matrix\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] < 0) {
                printf("%.2lf, ", A[i][j]);
            }
            else {
                printf(" %.2lf, ", A[i][j]);
            }
            
        }
        
        printf("\n");
    }
    
    printf("END matrix\n");

}

void Matrix::printaV (size_t m, double* V)
{
    printf("BEGIN vector\n");

    for (int i = 0; i < m; i++)
    {
        printf("%.2lf, ", V[i]);
    }
    
    printf("\nEND vector\n");
}

void Matrix::zera (size_t m, size_t n, double** A)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = 0.0;
        }
    }
}

void Matrix::zeraV (size_t m, double* v)
{
    for (int i = 0; i < m; i++)
    {
        v[i] = 0.0;
    }
}