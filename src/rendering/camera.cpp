//
//  camera.cpp
//  GameEngine3D
//
//  Created by Leonard Vollmann on 24/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#include "camera.h"

Camera::Camera(const Vector3f &pos, const Vector3f &forward, const Vector3f &up, float fov, float aspect, float zNear, float zFar) :
	m_pos(pos),
	m_forward(forward),
	m_up(up)
{
	setProjection(fov, aspect, zNear, zFar);
}

const Matrix4f Camera::getViewProjection() const
{
	Matrix4f view = Matrix4f().initView(m_pos, m_forward, m_up);
	return m_projection * view;
}
