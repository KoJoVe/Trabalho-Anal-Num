//
//  Physics.cpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 11/29/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#include "Physics.hpp"



// Constructors & Deconstructors
Physics::Physics()
{
    using namespace std;
    
    _particles = new vector<Particle*>;
    _bars = new vector<RigidBar*>;
    _springs = new vector<Spring*>;
    
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
    _force->calculateForce();
    //Calculate forces
    //Update position
    //Update velocity
}
//