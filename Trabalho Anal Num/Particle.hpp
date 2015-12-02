//
//  Particle.hpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 11/25/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stddef.h>
#include "Vec3.hpp"


class Particle
{
public:
    Particle();
    Particle(double mass);
    Particle(Vec3 position, double mass);
    ~Particle();
    
    
    Vec3 position;
    Vec3 velocity;
    double mass;
    
    bool hasGravity;
    
    Vec3 force;

    size_t index;
};


#endif /* Particle_hpp */
