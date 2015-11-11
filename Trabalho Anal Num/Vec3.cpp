//
//  Vec3.cpp
//  CompGraf
//
//  Created by Gabriel Coutinho de Paula on 10/12/15.
//  Copyright © 2015 Gabriel Coutinho de Paula. All rights reserved.
//

#include "Vec3.hpp"

#include <math.h>


// Constructors & Deconstructors
Vec3::Vec3()
{
    _v[0]=0.0;
    _v[1]=0.0;
    _v[2]=0.0;
}

Vec3::Vec3(double x, double y, double z)
{
    _v[0]=x;
    _v[1]=y;
    _v[2]=z;
}

Vec3::Vec3(double const v[3])
{
    _v[0]=v[0];
    _v[1]=v[1];
    _v[2]=v[2];
}


// Getters & Setters
inline void Vec3::set( double x, double y, double z)
{
    _v[0]=x;
    _v[1]=y;
    _v[2]=z;
}

inline void Vec3::set(const Vec3& rhs)
{
    _v[0]=rhs._v[0];
    _v[1]=rhs._v[1];
    _v[2]=rhs._v[2];
}


// Operators Override
inline bool Vec3::operator == (const Vec3& v) const
{
    return (_v[0]==v._v[0]) && (_v[1]==v._v[1]) && (_v[2]==v._v[2]);
}

inline bool Vec3::operator != (const Vec3& v) const
{
    return (_v[0]!=v._v[0]) || (_v[1]!=v._v[1]) || (_v[2]!=v._v[2]);
}

inline bool Vec3::operator <  (const Vec3& v) const
{
    if (_v[0]<v._v[0]) return true;
    else if (_v[0]>v._v[0]) return false;
    else if (_v[1]<v._v[1]) return true;
    else if (_v[1]>v._v[1]) return false;
    else return (_v[2]<v._v[2]);
}

inline double& Vec3::operator [] (int i)
{
    return _v[i];
}

inline double Vec3::operator [] (int i) const
{
    return _v[i];
}

inline double Vec3::operator * (const Vec3& rhs) const
{
    return _v[0]*rhs._v[0] + _v[1]*rhs._v[1] + _v[2]*rhs._v[2];
}

inline const Vec3 Vec3::operator ^ (const Vec3& rhs) const
{
    return Vec3(_v[1]*rhs._v[2]-_v[2]*rhs._v[1],
                _v[2]*rhs._v[0]-_v[0]*rhs._v[2],
                _v[0]*rhs._v[1]-_v[1]*rhs._v[0]);
}

inline const Vec3 Vec3::operator * (double rhs) const
{
    return Vec3(_v[0]*rhs, _v[1]*rhs, _v[2]*rhs);
}

inline Vec3& Vec3::operator *= (double rhs)
{
    _v[0]*=rhs;
    _v[1]*=rhs;
    _v[2]*=rhs;
    return *this;
}

inline const Vec3 Vec3::operator / (double rhs) const
{
    return Vec3(_v[0]/rhs, _v[1]/rhs, _v[2]/rhs);
}

inline Vec3& Vec3::operator /= (double rhs)
{
    _v[0]/=rhs;
    _v[1]/=rhs;
    _v[2]/=rhs;
    return *this;
}

inline const Vec3 Vec3::operator + (const Vec3& rhs) const
{
    return Vec3(_v[0]+rhs._v[0], _v[1]+rhs._v[1], _v[2]+rhs._v[2]);
}

inline Vec3& Vec3::operator += (const Vec3& rhs)
{
    _v[0] += rhs._v[0];
    _v[1] += rhs._v[1];
    _v[2] += rhs._v[2];
    return *this;
}

inline const Vec3 Vec3::operator - (const Vec3& rhs) const
{
    return Vec3(_v[0]-rhs._v[0], _v[1]-rhs._v[1], _v[2]-rhs._v[2]);
}

inline Vec3& Vec3::operator -= (const Vec3& rhs)
{
    _v[0]-=rhs._v[0];
    _v[1]-=rhs._v[1];
    _v[2]-=rhs._v[2];
    return *this;
}

inline const Vec3 Vec3::operator - () const
{
    return Vec3 (-_v[0], -_v[1], -_v[2]);
}

inline double Vec3::modulus() const
{
    return sqrtf( _v[0]*_v[0] + _v[1]*_v[1] + _v[2]*_v[2] );
}

inline double Vec3::modulus2() const
{
    return _v[0]*_v[0] + _v[1]*_v[1] + _v[2]*_v[2];
}

inline double Vec3::normalize()
{
    double norm = Vec3::modulus();
    if (norm > 0.0)
    {
        double inv = 1.0f/norm;
        _v[0] *= inv;
        _v[1] *= inv;
        _v[2] *= inv;
    }
    return( norm );
}

inline Vec3 Vec3::normalized() const
{
    double norm = Vec3::modulus();
    if (norm > 0.0)
    {
        double inv = 1.0f/norm;
        Vec3 normal(*this);
        normal *= inv;
        return normal;
    }
    else
    {
        return Vec3(0, 0, 0);
    }
}