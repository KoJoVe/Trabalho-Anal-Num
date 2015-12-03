//
//  main.cpp
//  Trabalho Anal Num
//
//  Created by Joao Nassar Galante Guedes on 11/11/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#include <iostream>


#include "Matrix.hpp"
#include "Vec3.hpp"

#include "Particle.hpp"

#include "RigidBar.hpp"
#include "Spring.hpp"

#include "Physics.hpp"





double** lagrange(int m, int n, double** J, double** dJ, double* w, double* f, double* v);


int main(int argc, const char * argv[])
{
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    
    Physics* phys = new Physics();
    
    Particle* p0 = new Particle(Vec3(1.0, .0, .0), 10);
    Particle* p1 = new Particle(Vec3(.0, .0, .0), 10);
    Particle* p2 = new Particle(Vec3(-1.0, .0, .0), 10);
    Particle* p3 = new Particle(Vec3(3.0, .0, 0.0), 10);
    
    p0->velocity = Vec3(2.0, .0, .0);
    p1->velocity = Vec3(2.0, .0, .0);
    p2->velocity = Vec3(2.0, .0, .0);

    p3->velocity = Vec3(3.0, .0, .0);
    
    
    phys->addParticle(p0);
    phys->addParticle(p1);
    phys->addParticle(p2);
    phys->addParticle(p3);

    phys->addBar(0, 1);
    phys->addBar(1, 2);
    phys->addBar(1, 3);
    
    phys->update();
    
    
    return 0;
}





