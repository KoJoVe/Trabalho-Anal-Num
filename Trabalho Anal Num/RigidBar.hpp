//
//  RigidBar.hpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 11/29/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#ifndef RigidBar_hpp
#define RigidBar_hpp

#include "Vec3.hpp"
#include "Particle.hpp"


class RigidBar
{
public:
    RigidBar(const Particle* particleOne, const Particle* particleTwo);
    ~RigidBar();
    
    
    Vec3 positionDiff() const;
    Vec3 velocityDiff() const;
    
    const Particle* p1;
    const Particle* p2;
    
    size_t index;
};

#endif /* RigidBar_hpp */
