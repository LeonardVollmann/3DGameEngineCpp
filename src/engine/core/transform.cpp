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

#include "transform.h"

Matrix4f Transform::getTransformation() const
{
	const Matrix4f scale = Matrix4f().initScale(m_scale);
	const Matrix4f translation = Matrix4f().initTranslation(m_translation);
	const Matrix4f rotation = m_rotation.toRotationMatrix();

	return translation * rotation * scale;
}

void Transform::rotate(const Quaternion &rotation)
{
	// m_rotation = Quaternion((m_rotation * rotation).normalized());
	m_rotation = m_rotation * rotation;
}

void Transform::rotate(const Vector3f &axis, float angle)
{
	rotate(Quaternion(axis, angle));
}

void Transform::translate(const Vector3f &translation)
{
	m_translation += translation;
}