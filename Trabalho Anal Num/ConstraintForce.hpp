//
//  ConstraintForce.hpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 12/3/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#ifndef ConstraintForce_hpp
#define ConstraintForce_hpp

#include <vector>

#include "Particle.hpp"
#include "RigidBar.hpp"


class ConstraintForce
{
public:
    // Constructors & Deconstructors
    ConstraintForce(const std::vector<Particle*>* particles, const std::vector<RigidBar*>* bars);
    ~ConstraintForce();
    
    // Force Methods
    void force(Vec3* f, Vec3* velOffset);
    void cacheStuff(); // If the _particles or _bars vector changes size, call this method!
    
private:    
    const std::vector<Particle*>* _particles;
    const std::vector<RigidBar*>* _bars;
    
    double*  _lastLambda;
    double*  _b;
    double** _A;
    double** _J;
};

#endif /* ConstraintForce_hpp */
