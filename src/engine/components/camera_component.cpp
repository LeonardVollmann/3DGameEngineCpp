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

#include "camera_component.h"

CameraComponent::CameraComponent(float fov, float aspect, float zNear, float zFar) :
	m_camera(Matrix4f().initPerspective(fov, aspect, zNear, zFar))
	{}

void CameraComponent::update(float delta)
{
	m_engine->getRenderingEngine()->setCamera(&m_camera);
}

void CameraComponent::setParent(Entity *parent)
{
	m_parent = parent;
	m_camera.setTransform(&getTransform());
}

void CameraComponent::setEngine(CoreEngine *engine)
{
	m_engine = engine;
	// TODO: move setting the renderingengine's camera to m_camera in here
}