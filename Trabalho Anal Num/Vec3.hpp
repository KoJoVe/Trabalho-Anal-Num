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
    typedef double value_type;

    value_type _v[3];

    // Constructors & Deconstructors
    Vec3();
    Vec3(value_type x, value_type y, value_type z);
    Vec3(value_type const v[3]);
    
    // Getters & Setters
    void set(value_type x, value_type y, value_type z);
    void set(const Vec3& rhs);

    inline value_type* ptr() { return _v; }
    inline const value_type* ptr() const { return _v; }
    
    inline value_type& x() { return _v[0]; }
    inline value_type& y() { return _v[1]; }
    inline value_type& z() { return _v[2]; }
    
    inline value_type x() const { return _v[0]; }
    inline value_type y() const { return _v[1]; }
    inline value_type z() const { return _v[2]; }

    
    // Operators Override
    bool operator == (const Vec3& v) const;
    bool operator != (const Vec3& v) const;
    bool operator <  (const Vec3& v) const;
    value_type& operator [] (int i);
    value_type operator [] (int i) const;
    
    value_type operator * (const Vec3& rhs) const;          // Dot product
    const Vec3 operator ^ (const Vec3& rhs) const;       // Cross product
    const Vec3 operator * (value_type rhs) const;           // Multiplication by scalar
    Vec3& operator *= (value_type rhs);                     // Unary multiplication by scalar
    const Vec3 operator / (value_type rhs) const;           // Division by scalar
    Vec3& operator /= (value_type rhs);                     // Unary division by scalar
    const Vec3 operator + (const Vec3& rhs) const;       // Binary vector add
    Vec3& operator += (const Vec3& rhs);                 // Unary vector add
    const Vec3 operator - (const Vec3& rhs) const;       // Binary vector subtract
    Vec3& operator -= (const Vec3& rhs);                 // Unary vector subtract
    const Vec3 operator - () const;                      // Negation operator. Returns the negative of the Vec3
    value_type modulus() const;                             // Modulus
    value_type modulus2() const;                            // Modulus squared
    value_type normalize();                                 // Normalizes the vector
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
