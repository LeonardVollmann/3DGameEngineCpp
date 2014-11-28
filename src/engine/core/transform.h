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

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "math.h"

class Transform
{
public:
	Transform(const Vector3f &scale = Vector3f(1.0f, 1.0f, 1.0f), const Vector3f &translation = Vector3f(0.0f, 0.0f, 0.0f), const Quaternion &rotation = Quaternion()) :
		m_scale(scale),
		m_translation(translation),
		m_rotation(rotation) {}

	Matrix4f getTransformation() const;
	void rotate(const Quaternion &rotation);
	void rotate(const Vector3f &axis, float angle);
	void translate(const Vector3f &translation);
	
	inline const Vector3f &getScale() const { return m_scale; }
	inline const Vector3f &getTranslation() const { return m_translation; }
	inline const Quaternion &getRotation() const { return m_rotation; }

	inline void setScale(const Vector3f &scale) { m_scale = scale; }
	inline void setTranslation(const Vector3f &translation) { m_translation = translation; }
	inline void setRotation(const Quaternion &rotation) { m_rotation = rotation; }
protected:
private:
	Vector3f m_scale;
	Vector3f m_translation;
	Quaternion m_rotation;
};

#endif
