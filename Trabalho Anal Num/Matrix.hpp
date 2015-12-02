//
//  Matriz.h
//  AnaliseNumerica
//
//  Created by Gabriel Coutinho de Paula on 8/12/15.
//  Copyright (c) 2015 Gabriel Coutinho de Paula. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp


class Matrix
{
public:
    static double** newMatrix (size_t m, size_t n);
    static void deleteMatrix (size_t m, double** A);
    static void transpose (size_t m, size_t n, double** A, double** T);
    static void multWithArray (size_t m, size_t n, double** A, double* v, double* w);
    static void mult (size_t m, size_t n, size_t q, double** A, double ** B, double** C);
    
    //
    static double** squareIdentity(size_t m);
    static void printaM (size_t m, size_t n, double** A);
    static void printaV (size_t m, double* V);
    static void zera (size_t m, size_t n, double** A);
    static void zeraV (size_t m, double* v);
    //
};


#endif /* Matrix_hpp */


