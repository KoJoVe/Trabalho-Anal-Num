//
//  Vec3.hpp
//  CompGraf
//
//  Created by Gabriel Coutinho de Paula on 10/12/15.
//  Copyright © 2015 Gabriel Coutinho de Paula. All rights reserved.
//

#ifndef Vec3_hpp
#define Vec3_hpp

class Vec3
{
public:
    double _v[3];

    // Constructors & Deconstructors
    Vec3();
    Vec3(double x, double y, double z);
    Vec3(double const v[3]);
    
    // Getters & Setters
    inline void set(double x, double y, double z);
    inline void set(const Vec3& rhs);

    
    inline double* ptr() { return _v; }
    inline const double* ptr() const { return _v; }

    
    // Operators Override
    inline bool operator == (const Vec3& v) const;
    inline bool operator != (const Vec3& v) const;
    inline bool operator <  (const Vec3& v) const;
    inline double& operator [] (int i);
    inline double operator [] (int i) const;
    
    inline double operator * (const Vec3& rhs) const;          // Dot product
    inline const Vec3 operator ^ (const Vec3& rhs) const;       // Cross product
    inline const Vec3 operator * (double rhs) const;           // Multiplication by scalar
    inline Vec3& operator *= (double rhs);                     // Unary multiplication by scalar
    inline const Vec3 operator / (double rhs) const;           // Division by scalar
    inline Vec3& operator /= (double rhs);                     // Unary division by scalar
    inline const Vec3 operator + (const Vec3& rhs) const;       // Binary vector add
    inline Vec3& operator += (const Vec3& rhs);                 // Unary vector add
    inline const Vec3 operator - (const Vec3& rhs) const;       // Binary vector subtract
    inline Vec3& operator -= (const Vec3& rhs);                 // Unary vector subtract
    inline const Vec3 operator - () const;                      // Negation operator. Returns the negative of the Vec3
    inline double modulus() const;                             // Modulus
    inline double modulus2() const;                            // Modulus squared
    inline double normalize();                                 // Normalizes the vector
    inline Vec3 normalized() const;                             // Returns a normalized copy of the vector
};

#endif /* Vec3_hpp */
