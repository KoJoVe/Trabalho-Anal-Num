//
//  Vec3.hpp
//  CompGraf
//
//  Created by Gabriel Coutinho de Paula on 10/12/15.
//  Copyright © 2015 Gabriel Coutinho de Paula. All rights reserved.
//

#ifndef Vec3_hpp
#define Vec3_hpp

#include <ostream>

class Vec3
{
public:
    double _v[3];

    // Constructors & Deconstructors
    Vec3();
    Vec3(double x, double y, double z);
    Vec3(double const v[3]);
    
    // Getters & Setters
    void set(double x, double y, double z);
    void set(const Vec3& rhs);

    inline double* ptr() { return _v; }
    inline const double* ptr() const { return _v; }
    
    inline double& x() { return _v[0]; }
    inline double& y() { return _v[1]; }
    inline double& z() { return _v[2]; }
    
    inline double x() const { return _v[0]; }
    inline double y() const { return _v[1]; }
    inline double z() const { return _v[2]; }

    
    // Operators Override
    bool operator == (const Vec3& v) const;
    bool operator != (const Vec3& v) const;
    bool operator <  (const Vec3& v) const;
    double& operator [] (int i);
    double operator [] (int i) const;
    
    double operator * (const Vec3& rhs) const;          // Dot product
    const Vec3 operator ^ (const Vec3& rhs) const;       // Cross product
    const Vec3 operator * (double rhs) const;           // Multiplication by scalar
    Vec3& operator *= (double rhs);                     // Unary multiplication by scalar
    const Vec3 operator / (double rhs) const;           // Division by scalar
    Vec3& operator /= (double rhs);                     // Unary division by scalar
    const Vec3 operator + (const Vec3& rhs) const;       // Binary vector add
    Vec3& operator += (const Vec3& rhs);                 // Unary vector add
    const Vec3 operator - (const Vec3& rhs) const;       // Binary vector subtract
    Vec3& operator -= (const Vec3& rhs);                 // Unary vector subtract
    const Vec3 operator - () const;                      // Negation operator. Returns the negative of the Vec3
    double modulus() const;                             // Modulus
    double modulus2() const;                            // Modulus squared
    double normalize();                                 // Normalizes the vector
    Vec3 normalized() const;                             // Returns a normalized copy of the vector
};

    inline std::ostream& operator << (std::ostream& output, const Vec3::Vec3& vec)
    {
        output << vec._v[0] << " "
        << vec._v[1] << " "
        << vec._v[2];
        return output;     // to enable cascading
    }


#endif /* Vec3_hpp */
