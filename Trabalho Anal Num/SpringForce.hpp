//
//  SpringForce.hpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 12/3/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#ifndef SpringForce_hpp
#define SpringForce_hpp

#include <vector>

#include "Particle.hpp"
#include "Spring.hpp"


class SpringForce
{
public:
    // Constructors & Deconstructors
    SpringForce(const std::vector<Spring*>* springs);
    ~SpringForce();
    
    // Force Methods
    void force(Vec3* f, Vec3* posOffset);
    
private:
    const std::vector<Spring*>* _springs;
};

#endif /* SpringForce_hpp */