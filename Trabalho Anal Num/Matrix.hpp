//
//  Matrix.hpp
//  Trabalho Anal Num
//
//  Created by Joao Nassar Galante Guedes on 11/11/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//  Teste de Commit
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <iostream>

class Matrix
{
public:
    // Constructors & Deconstructors
    Matrix (size_t n);
    Matrix (size_t n, size_t m);
    virtual ~Matrix ();
    
    // Operators Override

    
    
private:
    virtual void bananas() const;
    
};

#endif /* Matrix_hpp */


