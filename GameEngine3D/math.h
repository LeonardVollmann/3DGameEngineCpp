//
//  math.h
//  GameEngine3D
//
//  Created by Leonard Vollmann on 11/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#ifndef __GameEngine3D__math__
#define __GameEngine3D__math__

#define MATH_PI 3.1415926535897932384626433832795
#define toRadians(x) (float)((x) * (MATH_PI / 180.0f))
#define toDegrees(x) (float)((x) * (180.0f / MATH_PI))

#include <cmath>

class Quaternion;

template <typename T, unsigned int D>
class Vector
{
public:
    Vector() {}
    
    inline T operator[](unsigned int i) const { return values[i]; }
    inline T &operator[](unsigned int i) { return values[i]; }
    
    inline bool operator==(const Vector<T, D> &r) const
    {
        for (unsigned int i = 0; i < D; i++) {
            if ((*this)[i] != r[i]) {
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
            result[i] = (*this)[i] + r[i];
        }
        return result;
    }
    
    inline Vector<T, D> &operator-(const Vector<T, D> &r) const
    {
        Vector<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            result[i] = (*this)[i] - r[i];
        }
        return result;
    }
    
    inline Vector<T, D> &operator*(const T &r) const
    {
        Vector<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            result[i] = (*this)[i] * r;
        }
        return result;
    }

    inline Vector<T, D> &operator/(const T &r) const
    {
        Vector<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            result[i] = (*this)[i] / r;
        }
        return result;
    }
    
    inline Vector<T, D> &operator+=(const Vector<T, D> &r)
    {
        for (unsigned int i = 0; i < D; i++) {
            (*this)[i] += r[i];
        }
        return *this;
    }
    
    inline Vector<T, D> &operator-=(const Vector<T, D> &r)
    {
        for (unsigned int i = 0; i < D; i++) {
            (*this)[i] -= r[i];
        }
        return *this;
    }
    
    inline Vector<T, D> &operator*=(const T &r)
    {
        for (unsigned int i = 0; i < D; i++) {
            (*this)[i] *= r;
        }
        return *this;
    }
    
    inline Vector<T, D> &operator/=(const T &r)
    {
        for (unsigned int i = 0; i < D; i++) {
            (*this)[i] /= r;
        }
        return *this;
    }
    
    inline T dot(const Vector<T, D> &r) const
    {
        T result = 0;
        for (unsigned int i = 0; i < D; i++) {
            result += (*this)[i] * r[i];
        }
        return result;
    }
    
    inline T lengthSquared() const { return this->dot((*this)); }
    
    inline T length() const { return sqrt(this->lengthSquared()); }
    
    inline Vector<T, D> normalized() const
    {
        return *this / this->length();
    }
    
    inline Vector<T, D> lerp(const Vector<T, D> &r, const T &beta) const
    {
        Vector<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            result[i] = (1 - beta) * (*this)[i] + beta * r[i];
        }
        return result;
    }
protected:
private:
    T values[D];
};

template <typename T>
class Vector2 : public Vector<T, 2>
{
public:
    Vector2<T>() {}
    
    Vector2<T>(const Vector2<T> &r)
    {
        (*this) = r;
    }
    
    Vector2<T>(const T &x, const T &y)
    {
        (*this)[0] = x;
        (*this)[1] = y;
    }
    
    inline T getX() const { return *this[0]; }
    inline T getY() const { return *this[1]; }
    
    inline void setX(const T &x) { (*this)[0] = x; }
    inline void setY(const T &y) { (*this)[1] = y; }
        
    inline void set(const T &x, const T &y)
    {
        this->setX(x);
        this->setY(y);
    }
protected:
private:
};
    
template <typename T>
class Vector3 : public Vector<T, 3>
{
public:
    Vector3<T>() {}
    
    Vector3<T>(const Vector3<T> &r)
    {
        (*this) = r;
    }
    
    Vector3<T>(const T &x, const T &y, const T& z)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
    }
    
    inline T getX() const { return ((*this))[0]; }
    inline T getY() const { return ((*this))[1]; }
    inline T getZ() const { return ((*this))[2]; }
    
    inline void setX(const T &x) { ((*this))[0] = x; }
    inline void setY(const T &y) { ((*this))[1] = y; }
    inline void setZ(const T &z) { ((*this))[2] = z; }
    
    inline void set(const T &x, const T &y, const T &z)
    {
        this->setX(x);
        this->setY(y);
        this->setZ(z);
    }
    
    Vector3<T> cross(const Vector3<T> &r)
    {
        Vector3<T> result;
        
        result[0] = ((*this)[1] * r[2]) - (((*this))[2] * r[1]);
        result[1] = ((*this)[2] * r[0]) - (((*this))[0] * r[2]);
        result[2] = ((*this)[0] * r[1]) - (((*this))[1] * r[0]);
        
        return result;
    }
protected:
private:
};

template <typename T>
class Vector4 : public Vector<T, 4>
{
public:
    Vector4<T>() {}
    
    Vector4<T>(const Vector4<T> &r)
    {
        (*this) = r;
    }
    
    Vector4<T>(const T &x, const T &y, const T &z, const T &w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    
    inline T getX() const { return (*this)[0]; }
    inline T getY() const { return (*this)[1]; }
    inline T getZ() const { return (*this)[2]; }
    inline T getW() const { return (*this)[3]; }
    
    inline void setX(const T &x) { (*this)[0] = x; }
    inline void setY(const T &y) { (*this)[1] = y; }
    inline void setZ(const T &z) { (*this)[2] = z; }
    inline void setW(const T &w) { (*this)[3] = w; }
    
    inline void set(const T &x, const T &y, const T &z, const T &w)
    {
        this->setX(x);
        this->setY(y);
        this->setZ(z);
        this->setW(w);
    }
protected:
private:
};

class Vector3f : public Vector3<float>
{
public:
    Vector3f(float x = 0, float y = 0, float z = 0)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
    }
    
    Vector3f(const Vector3f &r)
    {
        (*this)[0] = r.getX();
        (*this)[1] = r.getY();
        (*this)[2] = r.getZ();
    }
    
    inline bool operator==(const Vector3f &r) const
    {
        for (unsigned int i = 0; i < 3; i++) {
            if ((*this)[i] != r[i]) {
                return false;
            }
        }
        return true;
    }
    
    inline bool operator!=(const Vector3f &r) const { return !this->operator==(r); }
    
    inline Vector3f operator+(const Vector3f &r) const
    {
        Vector3f result;
        result.setX(getX() + r.getX());
        result.setY(getY() + r.getY());
        result.setZ(getZ() + r.getZ());
        return result;
    }
    
    inline Vector3f operator-(const Vector3f &r) const
    {
        Vector3f result;
        result.setX(getX() - r.getX());
        result.setY(getY() - r.getY());
        result.setZ(getZ() - r.getZ());
        return result;
    }
    
    inline Vector3f operator*(float r) const
    {
        Vector3f result;
        result.setX(getX() * r);
        result.setY(getY() * r);
        result.setZ(getZ() * r);
        return result;
    }
    
    inline Vector3f operator/(float r) const
    {
        Vector3f result;
        result.setX(getX() / r);
        result.setY(getY() / r);
        result.setZ(getZ() / r);
        return result;
    }
    
    inline Vector3f operator+=(const Vector3f &r)
    {
        *this = this->operator+(r);
        return *this;
    }
    
    inline Vector3f operator-=(const Vector3f &r)
    {
        *this = this->operator-(r);
        return *this;
    }
    
    inline Vector3f operator*=(float r)
    {
        *this = this->operator*(r);
        return *this;
    }
    
    inline Vector3f operator/=(float r)
    {
        *this = this->operator/(r);
        return *this;
    }
    
    inline float dot(const Vector3f &r) const
    {
        float result = 0;
        for (unsigned int i = 0; i < 3; i++) {
            result += (*this)[i] * r[i];
        }
        return result;
    }
    
    inline Vector3f cross(const Vector3f &r)
    {
        Vector3f result;
        
        result[0] = ((*this)[1] * r[2]) - (((*this))[2] * r[1]);
        result[1] = ((*this)[2] * r[0]) - (((*this))[0] * r[2]);
        result[2] = ((*this)[0] * r[1]) - (((*this))[1] * r[0]);
        
        return result;
    }
    
    inline float lengthSquared() const { return this->dot((*this)); }
    
    inline float length() const { return sqrt(this->lengthSquared()); }
    
    inline Vector3f normalized() const
    {
        return *this / this->length();
    }
    
    inline Vector3f lerp(const Vector3f &r, const float &beta) const
    {
        Vector3f result;
        for (unsigned int i = 0; i < 3; i++) {
            result[i] = (1 - beta) * (*this)[i] + beta * r[i];
        }
        return result;
    }
    
    Vector3f rotate(const Quaternion &q);
protected:
private:
};

typedef Vector2<int>    Vector2i;
typedef Vector2<double> Vector2d;
typedef Vector2<float>  Vector2f;

typedef Vector3<int>    Vector3i;
typedef Vector3<double> Vector3d;
//typedef Vector3<float>  Vector3f;

typedef Vector4<int>    Vector4i;
typedef Vector4<double> Vector4d;
typedef Vector4<float>  Vector4f;

template <typename T, unsigned int D>
class Matrix
{
public:
    inline T operator[](unsigned int i) const { return matrix[i]; }
    inline T &operator[](unsigned int i) { return matrix[i]; }
    
    inline bool operator==(const Matrix<T, D> &r) const
    {
        for (unsigned int i = 0; i < D; i++) {
            for (unsigned int j = 0; j < D; j++) {
                if ((*this)[i][j] != r[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    inline bool operator!=(const Matrix<T, D> &r) const { return !this->operator==(r); }
    
    inline Matrix<T, D> initIdentity()
    {
        for (unsigned int i = 0; i < D; i++) {
            for (unsigned int j = 0; j < D; j++) {
                if (i == j) {
                    (*this)[i][j] = 1;
                } else {
                    (*this)[i][j] = 0;
                }
            }
        }
        return *this;
    }
    
    inline Matrix<T, D> initTranslation(const Vector<T, D - 1> &r)
    {
        for (unsigned int i = 0; i < D; i++) {
            for (unsigned int j = 0; j < D; j++) {
                if (i < D - 1 && j == D - 1) {
                    (*this)[i][j] = r[i];
                } else if (i == j) {
                    (*this)[i][j] = 1;
                } else {
                    (*this)[i][j] = 0;
                }
            }
        }
        return *this;
    }
    
    inline Matrix<T, D> initScale(const Vector<T, D> &r)
    {
        for (unsigned int i = 0; i < D; i++) {
            for (unsigned int j = 0; j < D; j++) {
                if (i == j && i < D - 1) {
                    (*this)[i][j] = r[i];
                } else if (i == j && i == D - 1) {
                    (*this)[i][j] = 1;
                } else {
                    (*this)[i][j] = 0;
                }
            }
        }
        return *this;
    }
    
    inline Vector<T, D> getRow(unsigned int row) const
    {
        Vector<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            result[i] = (*this)[row][i];
        }
        return result;
    }
    
    inline Vector<T, D> getCol(unsigned int col) const
    {
        Vector<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            result[i] = (*this)[i][col];
        }
        return result;
    }
    
    inline void setRow(unsigned int row, const Vector<T, D> &r)
    {
        for (unsigned int i = 0; i < D; i++) {
            (*this)[row][i] = r[i];
        }
    }
    
    inline void setCol(unsigned int col, const Vector<T, D> &r)
    {
        for (unsigned int i = 0; i < D; i++) {
            (*this)[i][col] = r[i];
        }
    }
    
    inline void set(unsigned int x, unsigned int y, const T &val) { (*this)[x][y] = val; }
    
    inline Matrix<T, D> operator*(const Matrix<T, D> &r) const
    {
        Matrix<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            for (unsigned int j = 0; j < D; j++) {
                result[i][j] = this->getRow(i).dot(r.getCol(j));
            }
        }
        return result;
    }
    
    inline Matrix<T, D> operator*=(const Matrix<T, D> &r)
    {
        *this = this->operator*(r);
        return *this;
    }
    
    inline Matrix<T, D> transposed() const
    {
        Matrix<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            for (unsigned int j = 0; j < D; j++) {
                result[i][j] = (*this)[j][i];
            }
        }
        return result;
    }
protected:
private:
    T matrix[D][D];
};

template <typename T>
class Matrix3 : public Matrix<T, 3>
{
public:
    Matrix3() {}
    
    template <unsigned int D>
    Matrix3(const Matrix<T, D> &r)
    {
        if (D < 3) {
            this->initIdentity();
            
            for (unsigned int i = 0; i < D; i++) {
                for (unsigned int j = 0; j < D; j++)
                {
                    (*this)[i][j] = r[i][j];
                }
            }
        } else {
            for (unsigned int i = 0; i < 3; i++) {
                for (unsigned int j = 0; j < 3; j++)
                {
                    (*this)[i][j] = r[i][j];
                }
            }
        }
    }
protected:
private:
};

template <typename T>
class Matrix4 : public Matrix<T, 4>
{
public:
    Matrix4() {}
    
    template <unsigned int D>
    Matrix4(const Matrix<T, D> &r)
    {
        if (D < 4) {
            this->initIdentity();
            
            for (unsigned int i = 0; i < D; i++) {
                for (unsigned int j = 0; j < D; j++)
                {
                    (*this)[i][j] = r[i][j];
                }
            }
        } else {
            for (unsigned int i = 0; i < 4; i++) {
                for (unsigned int j = 0; j < 4; j++)
                {
                    (*this)[i][j] = r[i][j];
                }
            }
        }
    }
protected:
private:
};

typedef Matrix3<int>    Matrix3i;
typedef Matrix3<double> Matrix3d;
typedef Matrix3<float>  Matrix3f;

typedef Matrix4<int>    Matrix4i;
typedef Matrix4<double> Matrix4d;
typedef Matrix4<float>  Matrix4f;

class Quaternion : public Vector4f
{
public:
    Quaternion() {}
    
    Quaternion(float x, float y, float z, float w)
    {
        this->setX(x);
        this->setY(y);
        this->setZ(z);
        this->setW(w);
    }
    
    Quaternion(const Vector3f &v, float w) :
        Quaternion(v.getX(), v.getY(), v.getZ(), w) {}
    
    inline Quaternion initFromAxisAngle(const Vector3f axis, float angle)
    {
        const float sinHalfAngle = sinf(angle / 2);
        const float cosHalfAngle = cosf(angle / 2);
        
        (*this)[0] = axis.getX() * sinHalfAngle;
        (*this)[1] = axis.getY() * sinHalfAngle;
        (*this)[2] = axis.getZ() * sinHalfAngle;
        (*this)[3] = cosHalfAngle;
        
        return *this;
    }
    
    inline Vector3f getXYZ() const { return Vector3f((*this)[0], (*this)[1], (*this)[2]); }
    
    inline Quaternion conjugate() const { return Quaternion(Vector3f(-(*this)[0], -(*this)[1], -(*this)[2]), (*this)[3]); }
    
    inline Quaternion operator*(const Quaternion &r) const
    {
        const float _x = (getX() * r.getW()) + (getW() * r.getX()) + (getY() * r.getZ()) - (getZ() * r.getY());
        const float _y = (getY() * r.getW()) + (getW() * r.getY()) + (getZ() * r.getX()) - (getX() * r.getZ());
        const float _z = (getZ() * r.getW()) + (getW() * r.getZ()) + (getX() * r.getY()) - (getY() * r.getX());
        const float _w = (getW() * r.getW()) - (getX() * r.getX()) - (getY() * r.getY()) - (getZ() * r.getZ());
        
        return Quaternion(_x, _y, _z, _w);
    }

    inline Quaternion operator*(const Vector3f &v) const
    {
        const float _x =  (getW() * v.getX()) + (getY() * v.getZ()) - (getZ() * v.getY());
        const float _y =  (getW() * v.getY()) + (getZ() * v.getX()) - (getX() * v.getZ());
        const float _z =  (getW() * v.getZ()) + (getX() * v.getY()) - (getY() * v.getX());
        const float _w = -(getX() * v.getX()) - (getY() * v.getY()) - (getZ() * v.getZ());
        
        return Quaternion(_x, _y, _z, _w);
    }
    
    inline Quaternion operator*=(const Quaternion &r)
    {
        *this = this->operator*(r);
        return *this;
    }
protected:
private:
};

#endif /* defined(__GameEngine3D__math__) */