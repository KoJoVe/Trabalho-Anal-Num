//
//  Matrix.hpp
//  Trabalho Anal Num
//
//  Created by Joao Nassar Galante Guedes on 11/11/15.
//  Copyright © 2015 Joao e Coutinho. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>

class Matrix
{
    
public:
    ~Matrix ();
    Matrix (size_t n);
    Matrix (size_t n, size_t m);
    
private:
    void bananas() const;
    
};

#endif /* Matrix_hpp */


