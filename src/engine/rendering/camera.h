/*
 * Copyright (c) 2014 Leonard Vollmann
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "../core/math.h"
#include "../core/input.h"
#include "../core/core_engine.h"

class Camera
{
public:
	Camera(const Matrix4f &projection) :
		m_projection(projection) {}

	inline const Matrix4f getViewProjection() const
	{
		Matrix4f view = Matrix4f().initView(m_transform->getTranslation(), m_transform->getRotation().getForward(), Vector3f(0.0f, 1.0f, 0.0f));//m_transform->getRotation().getUp());

		return m_projection * view;
	}

	inline const Matrix4f &getProjection() const { return m_projection; }
	inline const Transform &getTransform() const { return *m_transform; }
	inline Transform *getTransform() { return m_transform; }

	inline void setProjection(float fov, float aspect, float zNear, float zFar) { m_projection = Matrix4f().initPerspective(fov, aspect, zNear, zFar); }
	inline void setTransform(Transform *transform) { m_transform = transform; }
protected:
private:
	Matrix4f m_projection;
	Transform *m_transform;
};

#endif