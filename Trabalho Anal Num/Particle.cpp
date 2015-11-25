//
//  Particle.cpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 11/25/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#include "Particle.hpp"


Particle::Particle()
{
    this->position = new Vec3();
    this->mass = 0.0;
}

Particle::Particle(double mass)
{
    this->position = new Vec3();
    this->mass = mass;
}

Particle::Particle(Vec3* position, double mass)
{
    this->position = position;
    this->mass = mass;
}

Particle::~Particle()
{
    delete this->position;
}