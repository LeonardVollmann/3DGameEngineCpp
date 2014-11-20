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

#ifndef CAMERA_COMPONENT_H
#define CAMERA_COMPONENT_H

#include "../core/component.h"
#include "../core/transform.h"
#include "../rendering/camera.h"

class CameraComponent : public Component
{
public:
	CameraComponent(const Vector3f &pos, const Vector3f &forward, const Vector3f &up, float fov, float aspect, float zNear, float zFar);

	virtual void update(float delta);

	virtual void setParent(Entity *parent);
	virtual void setEngine(CoreEngine *engine);

	const Matrix4f getViewProjection() const;
protected:
private:
	Camera m_camera;

	Vector3f m_pos;
	Vector3f m_forward;
	Vector3f m_up;
};

#endif