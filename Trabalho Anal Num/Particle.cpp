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
    this->position = Vec3();
    this->velocity = Vec3();
    
    this->mass = 0.0;
    this->hasGravity = true;
}

Particle::Particle(double mass)
{
    this->position = Vec3();
    this->velocity = Vec3();
    
    this->mass = mass;
    this->hasGravity = true;
}

Particle::Particle(Vec3 position, double mass)
{
    this->position = position;
    this->velocity = Vec3();
    
    this->mass = mass;
    this->hasGravity = true;
}

Particle::~Particle()
{

}