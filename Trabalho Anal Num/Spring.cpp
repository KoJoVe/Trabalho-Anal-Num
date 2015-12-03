//
//  Spring.cpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 11/29/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#include "Spring.hpp"


Spring::Spring(const Particle* particleOne, const Particle* particleTwo, double stiffness, double relaxedDistance)
{
    this->stiffness = stiffness;
    this->relaxedDistance = relaxedDistance;
    
    p1 = particleOne;
    p2 = particleTwo;
}

Vec3 Spring::positionDiff() const
{
    return p1->position - p2->position;
}