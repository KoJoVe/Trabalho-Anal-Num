//
//  Force.hpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 11/28/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#ifndef Force_hpp
#define Force_hpp

#include <vector>

#include "Particle.hpp"
#include "RigidBar.hpp"
#include "Spring.hpp"

#include "ConstraintForce.hpp"
#include "SpringForce.hpp"


class Force
{
public:
    // Constructors & Deconstructors
    Force();
    ~Force();
    
    
    // Getters & Setters
    void setParticles(const std::vector<Particle*>* particles);
    void setSprings(const std::vector<Spring*>* springs);
    void setBars(const std::vector<RigidBar*>* bars);
    void setGravity(const Vec3* gravity);

    // Force Methods
    Vec3* calculateForce();
    
    
private:
    bool _firstRun;
    
    const Vec3* _gravity;
    const std::vector<Particle*>* _particles;
    const std::vector<Spring*>* _springs;
    const std::vector<RigidBar*>* _bars;
    
    SpringForce* _springForce;
    ConstraintForce* _constraintForce;
    
    
    void gravityForce(Vec3* f);
};

#endif /* Force_hpp */
