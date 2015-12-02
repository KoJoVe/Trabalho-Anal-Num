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


class Force
{
public:
    Force();
    ~Force();
    
    void setParticles(const std::vector<Particle*>* particles);
    void setSprings(const std::vector<Spring*>* springs);
    void setBars(const std::vector<RigidBar*>* bars);
    void setGravity(const double* gravity);

    
    Vec3* calculateForce();
    
    
private:
    void gravityForce(Vec3* f);
    void springForce(Vec3* f);
    void constraintForce(Vec3* f);
    
    void firstRun();
    
    const double* _gravity;
    const std::vector<Particle*>* _particles;
    const std::vector<Spring*>* _springs;
    const std::vector<RigidBar*>* _bars;
    
    double* _lastLambda;
    double** _A;
    double** _J;
};

#endif /* Force_hpp */
