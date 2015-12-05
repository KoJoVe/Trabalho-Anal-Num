//
//  Physics.hpp
//  Trabalho Anal Num
//
//  Created by Gabriel Coutinho de Paula on 11/29/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#ifndef Physics_hpp
#define Physics_hpp

#include <vector>


#include "Particle.hpp"

#include "RigidBar.hpp"
#include "Spring.hpp"

#include "Force.hpp"



class Physics
{
public:
    // Constructors & Deconstructors
    Physics();
    ~Physics();
    
    
    // World Setting Methods
    void addParticle(Particle* particle);
    void addBar(int i, int j);
    void addSpring(int i, int j, double stiffness, double r);
    void setGravity(Vec3 gravity);
    
    // Update Methods
    void update();
    
    
    void printaParticula();

private:
    double _h;
    
    std::vector<Particle*>* _particles;
    std::vector<RigidBar*>* _bars;
    std::vector<Spring*>* _springs;
    Vec3 _gravity;
    
    Force* _force;
};
#endif /* Physics_hpp */
