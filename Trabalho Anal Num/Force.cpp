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
#include <iomanip>
#include <math.h>



// Constructors & Deconstructors
Force::Force()
{
    _firstRun = true;
}

Force::~Force()
{
    
}
//


// Getters & Setters
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
//


// Force Methods
Vec3* Force::calculateForce()
{
    if(_firstRun)
    {
        _firstRun = false;
        _constraintForce = new ConstraintForce(_particles, _bars);
        _springForce = new SpringForce(_springs);
    }
    
    Vec3* force = new Vec3[_particles->size()];
    
    this->gravityForce(force);
    _springForce->force(force);
    _constraintForce->force(force);
    

    
    for (int i = 0; i < _particles->size(); i++) {
        std::cout << std::fixed << std::setw(11) << std::setprecision(6)
        << force[i] << std::endl;
    }
    
    return force;
}
//



// Private Methods
void Force::gravityForce(Vec3* f)
{
    const size_t count = _particles->size();
    for (size_t i = 0; i < count; i++)
    {
        const Particle* p = _particles->at(i);
        
        if (p->hasGravity) {
            f[i] = (*_gravity)*p->mass;
        }
        else {
            f[i].set(0.0, 0.0, 0.0);
        }
    }
}
