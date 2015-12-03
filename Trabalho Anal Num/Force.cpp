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


Force::Force()
{
    _firstRun = true;
    //_lastLambda = NULL;
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

void Force::setGravity(const Vec3* gravity)
{
    _gravity = gravity;
}


Vec3* Force::calculateForce()
{
    if(_firstRun) {
        _firstRun = false;
        
        _constraintForce = new ConstraintForce(_particles, _bars);
    }
    
    
    
    Vec3* force = new Vec3[_particles->size()];
    
//    if(!_lastLambda) {
//        this->firstRun();
//    }
    
    
    
    gravityForce(force);
    force[1].x() = 50.0;

    

    
    springForce(force);
    
//    for (int i = 0; i < _particles->size(); i++) {
//        std::cout << force[i] << std::endl;
//    }

    
    _constraintForce->constraintForce(force);
    
    //constraintForce(force);
    
    
    
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
        f[i].set(0.0, 0.0, 0.0);

    }
}

void Force::springForce(Vec3* f)
{
    
}
