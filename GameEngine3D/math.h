//
//  math.h
//  GameEngine3D
//
//  Created by Leonard Vollmann on 11/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#ifndef __GameEngine3D__math__
#define __GameEngine3D__math__

#define MATH_PI 3.14159265359

template <typename T, unsigned int D>
class Vector
{
public:
    Vector() {}
    
    inline T &operator[](unsigned int i) const { return values[i]; }
    inline T operator[](unsigned int i) const { return values[i]; }
    
    inline bool operator==(const Vector<T, D> &r) const
    {
        for (unsigned int i = 0; i < D; i++) {
            if (*this[i] != r[i]) {
                return false;
            }
        }
        return true;
    }
    
    inline bool operator!=(const Vector<T, D> &r) const { return !this->operator==(r); }
    
    inline Vector<T, D> &operator+(const Vector<T, D> &r) const
    {
        Vector<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            result[i] = *this[i] + r[i];
        }
        return result;
    }
    
    inline Vector<T, D> &operator-(const Vector<T, D> &r) const
    {
        Vector<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            result[i] = *this[i] - r[i];
        }
        return result;
    }
    
    inline Vector<T, D> &operator*(const T &r) const
    {
        Vector<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            result[i] = *this[i] * r;
        }
        return result;
    }

    inline Vector<T, D> &operator/(const T &r) const
    {
        Vector<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            result[i] = *this[i] / r;
        }
        return result;
    }
    
    inline Vector<T, D> &operator+=(const Vector<T, D> &r)
    {
        for (unsigned int i = 0; i < D; i++) {
            *this[i] += r[i];
        }
        return *this;
    }
    
    inline Vector<T, D> &operator-=(const Vector<T, D> &r)
    {
        for (unsigned int i = 0; i < D; i++) {
            *this[i] -= r[i];
        }
        return *this;
    }
    
    inline Vector<T, D> &operator*=(const T &r)
    {
        for (unsigned int i = 0; i < D; i++) {
            *this[i] *= r;
        }
        return *this;
    }
    
    inline Vector<T, D> &operator/=(const T &r)
    {
        for (unsigned int i = 0; i < D; i++) {
            *this[i] /= r;
        }
        return *this;
    }
    
    inline T dot(const Vector<T, D> &r) const
    {
        T result = 0;
        for (unsigned int i = 0; i < D; i++) {
            result += *this[i] * r[i];
        }
        return result;
    }
    
    inline T lengthSquared() const { return this->dot(*this); }
    
    inline T length() const { return sqrt(this->lengthSquared()); }
    
    inline Vector<T, D> normalize() const
    {
        return *this / this->length();
    }
protected:
private:
    T *values[D];
};

#endif /* defined(__GameEngine3D__math__) */
