//
//  Spring.cpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 11/29/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#include "Spring.hpp"


Spring::Spring(const Particle* particleOne, const Particle* particleTwo, double stiffness)
{
    this->stiffness = stiffness;
    p1 = particleOne;
    p2 = particleTwo;
}
