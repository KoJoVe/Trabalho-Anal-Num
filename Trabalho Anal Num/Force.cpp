//
//  Force.cpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 11/28/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#include "Force.hpp"

#include "Matrix.hpp"

#include <iostream>
#include <math.h>


static double SingleGaussSeidel(size_t n, double** A, double* b, double* x, double* answ);
static double* GaussSeidel(size_t n, double** A, double* b, double* x, double tol);


Force::Force()
{
    _lastLambda = NULL;
}


void Force::setParticles(const std::vector<Particle*>* particles)
{
    _particles = particles;
}

void Force::setSprings(const std::vector<Spring*>* springs)
{
    _springs = springs;
}

void Force::setBars(const std::vector<RigidBar*>* bars)
{
    _bars = bars;
}

void Force::setGravity(const double* gravity)
{
    _gravity = gravity;
}


Vec3* Force::calculateForce()
{
    Vec3* force = new Vec3[_particles->size()];
    
    if(!_lastLambda) {
        this->firstRun();
    }
    
    gravityForce(force);
    
        for (int i = 0; i < _particles->size(); i++) {
            std::cout << force[i] << std::endl;
        }

    
    springForce(force);
    constraintForce(force);
    
    
    
    for (int i = 0; i < _particles->size(); i++) {
        std::cout << force[i] << std::endl;
    }

    
    return force;
}



void Force::gravityForce(Vec3* f)
{
    const size_t count = _particles->size();
    for (int i = 0; i < count; i++)
    {
        f[i].set(0.0, 0.0, -100.0);
        //f[i].set(0.0, 0.0, 0.0);

    }
}

void Force::springForce(Vec3* f)
{
    
}



void Force::constraintForce(Vec3* f)
{
    const size_t pn = _particles->size()*3;
    const size_t bn = _bars->size();
    
    double*  b = new double[bn];
    
    for (size_t i = 0; i < bn; i++)
    {
        RigidBar* bar = _bars->at(i);
        
        const size_t i1 = bar->p1->index*3;
        const size_t i2 = bar->p2->index*3;
        
        const double mass1 = bar->p1->mass;
        const double mass2 = bar->p2->mass;
        
        Vec3 l = bar->positionDiff();
        const double mod  = l.modulus();
        l /= mod;
        
        // l time derivative
        Vec3 dl  = bar->velocityDiff();

        std::cout << l*(l*dl) << std::endl;
        std::cout << dl << std::endl;

        dl = (dl - l*(l*dl))/mod;

        //std::cout << dl << std::endl;

        
        // Calculate b
        Vec3 vel1 = bar->p1->velocity;
        Vec3 vel2 = bar->p2->velocity;
        b[i] = -l*(f[i1]/mass1 - f[i2]/mass2) - dl*vel1 + dl*vel2;
        //b[i] = - dl*vel1 + dl*vel2;


        std::cout << b[i] << std::endl;
    }
    
    
    _lastLambda = GaussSeidel(bn, _A, b, _lastLambda, 1/100000);
    
    
    for (size_t i = 0; i < pn; i+=3)
    {
        for (size_t j = 0; j < bn; j++)
        {
            f[i/3].x() += _J[j][i  ]*_lastLambda[j];
            f[i/3].y() += _J[j][i+1]*_lastLambda[j];
            f[i/3].z() += _J[j][i+2]*_lastLambda[j];
        }
    }
    
    delete b;
}


void Force::firstRun()
{
    const size_t pn = _particles->size()*3;
    const size_t bn = _bars->size();
    
    _J = Matrix::newMatrix(bn, pn);
    _A = Matrix::newMatrix(bn, bn);
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
    
    for (size_t i = 0; i < bn; i++)
    {
        for (size_t j = 0; j < bn; j++)
        {
            _A[i][j] = 0.0;
            for (size_t k = 0; k < pn; k++)
            {
                _A[i][j] += _J[j][k]*_J[i][k]/_particles->at(k/3)->mass;
            }
        }
    }
    
    
    _lastLambda = new double[bn];
    for (int i = 0; i < bn; i++) {
        _lastLambda[i] = 1.0;
    }
}




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
