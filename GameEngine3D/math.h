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
    
    inline Vector<T, D> lerp(const Vector<T, D> &r, const T &beta) const
    {
        Vector<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            result[i] = (1 - beta) * *this[i] + beta * r[i];
        }
        return result;
    }
protected:
private:
    T *values[D];
};

template <typename T>
class Vector2 : public Vector<T, 2>
{
public:
    Vector2<T>() {}
    
    Vector2<T>(const Vector2<T> &r)
    {
        *this = r;
    }
    
    Vector2<T>(const T &x, const T &y)
    {
        *this[0] = x;
        *this[1] = y;
    }
    
    inline T getX() const { return values[0]; }
    inline T getY() const { return values[1]; }
    
    inline void setX(const T &x) { *this[0] = x; }
    inline void setY(const T &y) { *this[1] = y; ]
        
    inline void set(const T &x, const T &y)
    {
        this->setX(x);
        this->setY(y);
    }
protected:
private:
};

#endif /* defined(__GameEngine3D__math__) */
