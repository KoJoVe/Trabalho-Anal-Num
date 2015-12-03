//
//  ConstraintForce.cpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 12/3/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#include "ConstraintForce.hpp"

#include <iostream>
#include <math.h>

#include "Matrix.hpp"

// Static Methods Declaration
static void ConjugateGradient (size_t n, double** A, double* b, double* x);
//



// Constructors & Deconstructors
ConstraintForce::ConstraintForce(const std::vector<Particle*>* particles, const std::vector<RigidBar*>* bars)
{
    _particles = particles;
    _bars = bars;
    
    _lastLambda = NULL;
    _J = NULL;
    
    _A = NULL;
    _b = NULL;
    
    this->cacheStuff();
}

ConstraintForce::~ConstraintForce()
{
    delete _lastLambda;
    delete _J;

    delete _A;
    delete _b;
}
//


// Force Methods
void ConstraintForce::force(Vec3* f)
{
    const size_t pn = _particles->size()*3;
    const size_t bn = _bars->size();
    

    for (size_t i = 0; i < bn; i++)
    {
        const RigidBar* bar = _bars->at(i);
        
        const size_t i1 = bar->p1->index;
        const size_t i2 = bar->p2->index;
        
        const double mass1 = bar->p1->mass;
        const double mass2 = bar->p2->mass;

        const Vec3 posDif = bar->positionDiff();
        const Vec3 velDif  = bar->velocityDiff();
        
        const double mod  = posDif.modulus();

        Vec3 l = posDif/mod;
        Vec3 dl = (velDif - l*(l*velDif))/mod;

        _b[i] = l*(f[i2]/mass2 - f[i1]/mass1) - dl*(velDif);
    }
    
    ConjugateGradient(bn, _A, _b, _lastLambda);
    
    for (size_t i = 0, i_3 = 0; i < pn; i+=3, i_3++)
    {
        for (size_t j = 0; j < bn; j++)
        {
            f[i_3].x() += _J[j][i  ]*_lastLambda[j];
            f[i_3].y() += _J[j][i+1]*_lastLambda[j];
            f[i_3].z() += _J[j][i+2]*_lastLambda[j];
        }
    }
}

void ConstraintForce::cacheStuff()
{
    delete _lastLambda;
    delete _A;
    delete _J;
    delete _b;
    
    const size_t pn = _particles->size()*3;
    const size_t bn = _bars->size();
    
    _J = Matrix::newMatrix(bn, pn);
    Matrix::zera(bn, pn, _J);
    
    for (size_t i = 0; i < bn; i++)
    {
        RigidBar* bar = _bars->at(i);
        
        const size_t i1 = bar->p1->index*3;
        const size_t i2 = bar->p2->index*3;
        
        Vec3 l = bar->positionDiff().normalized();
        
        _J[i][i1  ] = l.x();
        _J[i][i1+1] = l.y();
        _J[i][i1+2] = l.z();
        
        _J[i][i2  ] = -l.x();
        _J[i][i2+1] = -l.y();
        _J[i][i2+2] = -l.z();
    }
    
    _A = Matrix::newMatrix(bn, bn);

    for (size_t i = 0; i < bn; i++)
    {
        for (size_t j = 0; j < bn; j++)
        {
            _A[i][j] = 0.0;
            
            double& Aij = _A[i][j];
            double*& Jj = _J[j];
            double*& Ji = _J[i];

            for (size_t k = 0, k_3 = 0; k < pn; k+=3, k_3++)
            {
                const double mass = _particles->at(k_3)->mass;
                
                Aij += Jj[k  ]*Ji[k  ]/mass;
                Aij += Jj[k+1]*Ji[k+1]/mass;
                Aij += Jj[k+2]*Ji[k+2]/mass;
            }
        }
    }
    
    _b = new double[bn];

    _lastLambda = new double[bn];
    for (int i = 0; i < bn; i++) {
        _lastLambda[i] = 1.0;
    }
}
//



// Static Methods Definition
static void ConjugateGradient (size_t n, double** A, double* b, double* x)
{
    double* dk = new double[n];
    double* rk = new double[n];
    double* dn = new double[n];
    
    Matrix::multWithArray(n, n, A, x, dk);
    
    for (int i = 0; i < n; i++)
    {
        rk[i] = b[i] - dk[i];
        dk[i] = rk[i];
    }
    
    for (int k = 0; k < n; k++)
    {
        int stop = 1;
        
        for (int i = 0; i < n; i++) {
            if(rk[i] != 0) {
                stop = 0;
            }
        }
        
        if(stop == 1) {
            for (int i = 0; i < n; i++) {
                x[i] = x[i];
            }
            break;
        }
        
        double n1 = 0;
        double n2 = 0;
        
        for (int i = 0; i < n; i++) {
            n1 += rk[i] * rk[i];
        }
        
        Matrix::multWithArray(n, n, A, dk, dn);
        
        for (int i = 0; i < n; i++) {
            n2 += dk[i] * dn[i];
        }
        
        double alpha = n1/n2;
        
        for (int i = 0; i < n; i++) {
            x[i]  += alpha * dk[i];
            rk[i] -= alpha * dn[i];
        }
        
        n2 = 0;
        
        for (int i = 0; i < n; i++) {
            n2 += rk[i] * rk[i];
        }
        
        double beta = n2/n1;
        
        for (int i = 0; i < n; i++) {
            dk[i] = rk[i] + (beta * dk[i]);
        }
    }
    
    delete dk;
    delete rk;
    delete dn;
}
//










/*
static double SingleGaussSeidel(size_t n, double** A, double* b, double* x, double* answ);
static double* GaussSeidel(size_t n, double** A, double* b, double* x, double tol);

static double SingleGaussSeidel(size_t n, double** A, double* b, double* x, double* answ)
{
    double tol = 0.0;
    
    for (int i = 0; i < n; i++)
    {
        answ[i] = 0.0;
        
        for(int j = 0; j < n; j++)
        {
            if(i==j) {
                continue;
            }
            if (i > j) {
                answ[i] += A[i][j]*answ[j];
            }
            if(i < j) {
                answ[i] += A[i][j]*x[j];
            }
        }
        
        answ[i] = (b[i] - answ[i])/A[i][i];
        
        const double dif = answ[i] - x[i];
        tol += dif*dif;
    }
    return sqrt(tol);
}

static double* GaussSeidel(size_t n, double** A, double* b, double* x, double tol)
{
    double* next = new double[n];
    
    int i = 0;
    double currentTol;
    
    do
    {
        i++;
        currentTol = SingleGaussSeidel(n, A, b, x, next);
        
        double* temp = x;
        x = next;
        next = temp;
        
    } while(currentTol > tol);
    
    delete next;
    
    return x;
}
*/