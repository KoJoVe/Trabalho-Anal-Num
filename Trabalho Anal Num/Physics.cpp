//
//  Physics.cpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 11/29/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#include "Physics.hpp"


Physics::Physics()
{
    using namespace std;
    
    _particles = new vector<Particle*>;
    _bars = new vector<RigidBar*>;
    _springs = new vector<Spring*>;
    
    _force = new Force();
    _force->setParticles(_particles);
    _force->setSprings(_springs);
    _force->setBars(_bars);
}

Physics::~Physics()
{
    delete _particles;
    delete _bars;
    delete _springs;
}


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

void Physics::addSpring(int i, int j, double stiffness)
{
    const Particle* p1 = _particles->at(i);
    const Particle* p2 = _particles->at(j);
    
    _springs->push_back(new Spring(p1, p2, stiffness));
}




void Physics::update()
{
    _force->calculateForce();
    //Calculate forces
    //Update position
    //Update velocity
}

