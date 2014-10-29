//
//  camera.h
//  GameEngine3D
//
//  Created by Leonard Vollmann on 28/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#ifndef __GameEngine3D__camera__
#define __GameEngine3D__camera__

#include "../core/math.h"

class Camera
{
public:
	Camera(const Vector3f &pos, const Vector3f &forward, const Vector3f &up, float fov, float aspect, float zNear, float zFar);

	inline const Matrix4f &getProjection() const { return m_projection; }

	inline void setProjection(float fov, float aspect, float zNear, float zFar) { m_projection = Matrix4f().initProjection(fov, aspect, zNear, zFar); }
protected:
private:
	Vector3f m_pos;
	Vector3f m_forward;
	Vector3f m_up;

	Matrix4f m_projection;
};

#endif /* defined(__GameEngine3D__camera__) */