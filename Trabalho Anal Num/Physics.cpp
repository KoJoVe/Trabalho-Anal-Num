//
//  Physics.cpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 11/29/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#include "Physics.hpp"

#include <iostream>


// Constructors & Deconstructors
Physics::Physics()
{
    using namespace std;
    
    _particles = new vector<Particle*>;
    _bars = new vector<RigidBar*>;
    _springs = new vector<Spring*>;
    
    _h = 1/100000.0;
    
    _gravity = Vec3(0.0, -9.8, 0.0);
    
    _force = new Force();
    _force->setParticles(_particles);
    _force->setSprings(_springs);
    _force->setBars(_bars);
    _force->setGravity(&_gravity);
}

Physics::~Physics()
{
    delete _particles;
    delete _bars;
    delete _springs;
}
//


// World Setting Methods
void Physics::addParticle(Particle* particle)
{
    particle->index = _particles->size();
    _particles->push_back(particle);
}

void Physics::addBar(int i, int j)
{
    const Particle* p1 = _particles->at(i);
    const Particle* p2 = _particles->at(j);
    RigidBar* bar = new RigidBar(p1, p2);
    
    bar->index = _bars->size();
    _bars->push_back(bar);
}

void Physics::addSpring(int i, int j, double stiffness, double r)
{
    const Particle* p1 = _particles->at(i);
    const Particle* p2 = _particles->at(j);
    
    _springs->push_back(new Spring(p1, p2, stiffness, r));
}

void Physics::setGravity(Vec3 gravity)
{
    _gravity = gravity;
}
//


// Update Methods
void Physics::update()
{
    const size_t pn = _particles->size();
    
    Vec3* p1 = new Vec3[pn];
    Vec3* v1 = new Vec3[pn];

    
    Vec3* force = _force->calculateForce(p1, v1);
    
    
    // Euler
    for (size_t i = 0; i < pn; i++)
    {
        Particle* particle = _particles->at(i);

        particle->position += particle->velocity*_h;
        particle->velocity += force[i]*_h*_particles->at(i)->w;
    }

    
// Runge-Kutta, not working :/
//    for (size_t i = 0; i < pn; i++)
//    {
//        p1[i] = _particles->at(i)->velocity*_h/2;
//        v1[i] = force[i]*_h/2/_particles->at(i)->mass;
//    }
//    
//    force = _force->calculateForce(p1, v1);
//    
//    Vec3* p2 = new Vec3[pn];
//    Vec3* v2 = new Vec3[pn];
//    for (size_t i = 0; i < pn; i++)
//    {
//        p2[i] = v1[i]*_h/2;
//        v2[i] = force[i]*_h/2/_particles->at(i)->mass;
//    }
//
//    force = _force->calculateForce(p2, v2);
//    
//    Vec3* p3 = new Vec3[pn];
//    Vec3* v3 = new Vec3[pn];
//    for (size_t i = 0; i < pn; i++)
//    {
//        p3[i] = v2[i]*_h;
//        v3[i] = force[i]*_h/_particles->at(i)->mass;
//    }
//    
//    force = _force->calculateForce(p3, v3);
//
//    Vec3* p4 = new Vec3[pn];
//    Vec3* v4 = new Vec3[pn];
//    for (size_t i = 0; i < pn; i++)
//    {
//        p4[i] = v3[i]*_h;
//        v4[i] = force[i]*_h/_particles->at(i)->mass;
//    }
//    
//    for (size_t i = 0; i < pn; i++)
//    {
//        Particle* particle = _particles->at(i);
//        
//        particle->position += p1[i]/3.0 + (p2[i] + p3[i] + p4[i])/6.0;
//        particle->velocity += v1[i]/3.0 + (v2[i] + v3[i] + v4[i])/6.0;
//    }
    

    
    
    
    
    
//    const double s1 = h*f(t, yt);
//    const double s2 = h*f(t + h/2.0, yt + s1/2.0);
//    const double s3 = h*f(t + h/2.0, yt + s2/2.0);
//    const double s4 = h*f(t + h, yt + s3);
//    
//    return yt + 1/6.0*(s1+2*s2+2*s3+s4);

    
    
    //Calculate forces
    //Update position
    //Update velocity
}
//



void Physics::printaParticula()
{
    
    const size_t pn = _particles->size();
    
    
    for (size_t i = 0; i < pn; i++)
    {
        Particle* particle = _particles->at(i);

        std::cout << particle->position << ", " << particle->velocity << std::endl;
    }
    
    std::cout << std::endl;
}







double SingleRungerStep(double t, double yt, double h, double (*f) (double t, double y));


double RungerKutta(double t0, double t1, double h, double y0, double (*f) (double t, double y))
{
    double yt = y0;

    for (double t = t0; t < t1; t += h)
    {
        yt = SingleRungerStep(t, yt, h, f);
    }

    return yt;
}

double SingleRungerStep(double t, double yt, double h, double (*f) (double t, double y))
{
    const double s1 = h*f(t, yt);
    const double s2 = h*f(t + h/2.0, yt + s1/2.0);
    const double s3 = h*f(t + h/2.0, yt + s2/2.0);
    const double s4 = h*f(t + h, yt + s3);
    
    return yt + 1/6.0*(s1+2*s2+2*s3+s4);
}



