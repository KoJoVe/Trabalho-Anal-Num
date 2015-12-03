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
    Physics();
    ~Physics();
    
    void addParticle(Particle* particle);
    void addBar(int i, int j);
    void addSpring(int i, int j, double stiffness);

    
    void update();


private:
    double h;
    
    Vec3 gravity;
    std::vector<Particle*>* _particles;
    std::vector<RigidBar*>* _bars;
    std::vector<Spring*>* _springs;
    
    Force* _force;
};
#endif /* Physics_hpp */
