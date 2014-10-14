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

#include <cmath>

template <typename T, unsigned int D>
class Vector
{
public:
    Vector() {}
    
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
    
    inline Vector<T, D> normalized() const
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
    T values[D];
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
    
    inline T getX() const { return *this[0]; }
    inline T getY() const { return *this[1]; }
    
    inline void setX(const T &x) { *this[0] = x; }
    inline void setY(const T &y) { *this[1] = y; }
        
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
        *this = r;
    }
    
    Vector3<T>(const T &x, const T &y, const T& z)
    {
        *this[0] = x;
        *this[1] = y;
        *this[2] = z;
    }
    
    inline T getX() const { return *this[0]; }
    inline T getY() const { return *this[1]; }
    inline T getZ() const { return *this[2]; }
    
    inline void setX(const T &x) { *this[0] = x; }
    inline void setY(const T &y) { *this[1] = y; }
    inline void setZ(const T &z) { *this[2] = z; }
    
    inline void set(const T &x, const T &y, const T &z)
    {
        this->setX(x);
        this->setY(y);
        this->setZ(z);
    }
    
    Vector3<T> cross(const Vector3<T> &r)
    {
        Vector3<T> result;
        
        result[0] = (*this[1] * r[2]) - (*this[2] * r[1]);
        result[1] = (*this[2] * r[0]) - (*this[0] * r[2]);
        result[2] = (*this[0] * r[1]) - (*this[1] * r[0]);
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
        *this = r;
    }
    
    Vector4<T>(const T &x, const T &y, const T &z, const T &w)
    {
        *this[0] = x;
        *this[1] = y;
        *this[2] = z;
        *this[3] = w;
    }
    
    inline T getX() const { return *this[0]; }
    inline T getY() const { return *this[1]; }
    inline T getZ() const { return *this[2]; }
    inline T getW() const { return *this[3]; }
    
    inline void setX(const T &x) { *this[0] = x; }
    inline void setY(const T &y) { *this[1] = y; }
    inline void setZ(const T &z) { *this[2] = z; }
    inline void setW(const T &w) { *this[3] = w; }
    
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

typedef Vector2<char>   Vector2c;
typedef Vector2<short>  Vector2s;
typedef Vector2<int>    Vector2i;
typedef Vector2<long>   Vector2l;
typedef Vector2<double> Vector2d;
typedef Vector2<float>  Vector2f;

typedef Vector3<char>   Vector3c;
typedef Vector3<short>  Vector3s;
typedef Vector3<int>    Vector3i;
typedef Vector3<long>   Vector3l;
typedef Vector3<double> Vector3d;
typedef Vector3<float>  Vector3f;

typedef Vector4<char>   Vector4c;
typedef Vector4<short>  Vector4s;
typedef Vector4<int>    Vector4i;
typedef Vector4<long>   Vector4l;
typedef Vector4<double> Vector4d;
typedef Vector4<float>  Vector4f;

template <typename T, unsigned int D>
class Matrix
{
public:
    inline T operator[](unsigned int i) const { return matrix[i]; }
    
    inline bool operator==(const Matrix<T, D> &r) const
    {
        for (unsigned int i = 0; i < D; i++) {
            for (unsigned int j = 0; j < D; j++) {
                if (*this[i][j] != r[i][j]) {
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
                    *this[i][j] = 1;
                } else {
                    *this[i][j] = 0;
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
                    *this[i][j] = r[i];
                } else if (i == j) {
                    *this[i][j] = 1;
                } else {
                    *this[i][j] = 0;
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
                    *this[i][j] = r[i];
                } else if (i == j && i == D - 1) {
                    *this[i][j] = 1;
                } else {
                    *this[i][j] = 0;
                }
            }
        }
    }
    
    inline Vector<T, D> getRow(unsigned int row) const
    {
        Vector<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            result[i] = *this[row][i];
        }
        return result;
    }
    
    inline Vector<T, D> getCol(unsigned int col) const
    {
        Vector<T, D> result;
        for (unsigned int i = 0; i < D; i++) {
            result[i] = *this[i][col];
        }
        return result;
    }
    
    inline void setRow(unsigned int row, const Vector<T, D> &r)
    {
        for (unsigned int i = 0; i < D; i++) {
            *this[row][i] = r[i];
        }
    }
    
    inline void setCol(unsigned int col, const Vector<T, D> &r)
    {
        for (unsigned int i = 0; i < D; i++) {
            *this[i][col] = r[i];
        }
    }
    
    inline void set(unsigned int x, unsigned int y, const T &val) { *this[x][y] = val; }
    
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
                result[i][j] = *this[j][i];
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
                    *this[i][j] = r[i][j];
                }
            }
        } else {
            for (unsigned int i = 0; i < 3; i++) {
                for (unsigned int j = 0; j < 3; j++)
                {
                    *this[i][j] = r[i][j];
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
                    *this[i][j] = r[i][j];
                }
            }
        } else {
            for (unsigned int i = 0; i < 4; i++) {
                for (unsigned int j = 0; j < 4; j++)
                {
                    *this[i][j] = r[i][j];
                }
            }
        }
    }
protected:
private:
};

typedef Matrix3<char>   Matrix3c;
typedef Matrix3<short>  Matrix3s;
typedef Matrix3<int>    Matrix3i;
typedef Matrix3<long>   Matrix3l;
typedef Matrix3<double> Matrix3d;
typedef Matrix3<float>  Matrix3f;

typedef Matrix4<char>   Matrix4c;
typedef Matrix4<short>  Matrix4s;
typedef Matrix4<int>    Matrix4i;
typedef Matrix4<long>   Matrix4l;
typedef Matrix4<double> Matrix4d;
typedef Matrix4<float>  Matrix4f;

class Quaternion : public Vector4f
{
public:
    Quaternion() {}
    
    inline Quaternion initFromAxisAngle(const Vector3f axis, float angle)
    {
        this->setX(axis.getX() * sinf(angle / 2));
        this->setY(axis.getY() * sinf(angle / 2));
        this->setZ(axis.getZ() * sinf(angle / 2));
        this->setW(cosf(angle / 2));
        return *this;
    }
protected:
private:
};

#endif /* defined(__GameEngine3D__math__) */