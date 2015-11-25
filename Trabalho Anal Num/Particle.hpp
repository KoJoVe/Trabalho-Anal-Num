//
//  Particle.hpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 11/25/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

#include "Vec3.hpp"


class Particle
{
public:
    Particle();
    Particle(double mass);
    Particle(Vec3* position, double mass);
    
    ~Particle();
    
    Vec3* position;
    double mass;
};


#endif /* Particle_hpp */
