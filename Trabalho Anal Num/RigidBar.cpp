//
//  RigidBar.cpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 11/29/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#include "RigidBar.hpp"


RigidBar::RigidBar(const Particle* particleOne, const Particle* particleTwo)
{
    p1 = particleOne;
    p2 = particleTwo;
}


Vec3 RigidBar::positionDiff()
{
    return p1->position - p2->position;
}

Vec3 RigidBar::velocityDiff()
{
    return p1->velocity - p2->velocity;
}
