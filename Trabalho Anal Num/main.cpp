//
//  main.cpp
//  Trabalho Anal Num
//
//  Created by Joao Nassar Galante Guedes on 11/11/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#include <iostream>


#include "Matrix.hpp"
#include "Vec3.hpp"

#include "Particle.hpp"

#include "RigidBar.hpp"
#include "Spring.hpp"

#include "Physics.hpp"





double** lagrange(int m, int n, double** J, double** dJ, double* w, double* f, double* v);


int main(int argc, const char * argv[])
{
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    
    Physics* phys = new Physics();
    
    Particle* p0 = new Particle(Vec3(2.0, .0, .0), 10);
    Particle* p1 = new Particle(Vec3(.0, .0, .0), 10);
    Particle* p2 = new Particle(Vec3(-1.0, .0, .0), 10);
//    Particle* p3 = new Particle(Vec3(3.0, .0, 0.0), 10);
    
    p0->velocity = Vec3(2.0, .0, .0);
    p1->velocity = Vec3(2.0, .0, .0);
    p2->velocity = Vec3(2.0, .0, .0);

//    p3->velocity = Vec3(3.0, .0, .0);
    
    
    phys->addParticle(p0);
    phys->addParticle(p1);
    phys->addParticle(p2);
//    phys->addParticle(p4);

    phys->addBar(0, 1);
    phys->addBar(1, 2);
    //phys->addBar(1, 3);
    
    phys->update();
    
    
    
    
//    double** A = Matrix::newMatrix(5, 10);
//    double** W = Matrix::newMatrix(10, 10);
//    double* w = (double*) malloc(sizeof(double)*10);
//
//    double** At = Matrix::newMatrix(10, 5);
//    double** B = Matrix::newMatrix(5, 10);
//    double** answ = Matrix::newMatrix(5, 5);
//    
//    
//    for (int i = 0; i < 5; i++)
//    {
//        for (int j = 0; j < 10; j++)
//        {
//            A[i][j] = rand();
//            W[i][j] = 0.0;
//        }
//    }
//    
//    Matrix::transposeMatrix(5, 10, A, At);
//    
//    for (int i = 0; i < 10; i++)
//    {
//        w[i] = rand();
//        W[i][i] = w[i];
//    }
//
//    
//    
//    Matrix::mulMatrix(5, 10, 10, A, W, B);
//    Matrix::mulMatrix(5, 10, 5, B, At, answ);
//    Matrix::mat_printaM(5, 5, answ);
//
//    lagrange(5, 10, A, NULL, w, NULL, NULL);

    
    return 0;
}




double** lagrange(int m, int n, double** J, double** dJ, double* w, double* f, double* v)
{
    double** A = Matrix::newMatrix(m, m);
    double*  b = (double*) malloc(sizeof(double)*m);
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = 0.0;
            b[j] = 0.0;
            for (int k = 0; k < n; k++)
            {
                const double Jw = J[j][k]*w[k];
                
                A[i][j] += Jw*J[i][k];
                //b[j] += Jw*f[k];
            }
        }
    }
    
    
    Matrix::printaM(m, m, A);

    
    return NULL;
}





