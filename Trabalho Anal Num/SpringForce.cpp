//
//  SpringForce.cpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 12/3/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#include "SpringForce.hpp"

// Constructors & Deconstructors
SpringForce::SpringForce(const std::vector<Spring*>* springs)
{
    _springs = springs;
}

SpringForce::~SpringForce()
{
    
}
//


// Force Methods
void SpringForce::force(Vec3* f)
{
    const size_t sn = _springs->size();
    
    for (size_t i = 0; i < sn; i++)
    {
        const Spring* spring = _springs->at(i);
        
        const size_t i1 = spring->p1->index;
        const size_t i2 = spring->p2->index;

        const double k = spring->stiffness;
        const double r = spring->relaxedDistance;
        
        const Vec3 d = spring->positionDiff();
        
        const double mod = d.modulus();
        const Vec3 dn = d/mod;
        
        const Vec3 force = dn*(k*(r-mod));

        f[i1] += force;
        f[i2] -= force;
    }
}
//