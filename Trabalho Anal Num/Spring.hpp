//
//  Spring.hpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 11/29/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#ifndef Spring_hpp
#define Spring_hpp

#include "Vec3.hpp"
#include "Particle.hpp"


class Spring
{
public:
    Spring(const Particle* particleOne, const Particle* particleTwo, double stiffness, double relaxedDistance);
    ~Spring();
    Vec3 positionDiff() const;

    
    double stiffness;
    double relaxedDistance;

    const Particle* p1;
    const Particle* p2;
};

#endif /* Spring_hpp */
