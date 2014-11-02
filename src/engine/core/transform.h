//
//  transform.h
//  GameEngine3D
//
//  Created by Leonard Vollmann on 28/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#ifndef __GameEngine3D__transform__
#define __GameEngine3D__transform__

#include "math.h"

class Transform
{
public:
	Transform(const Vector3f &scale = Vector3f(1.0f, 1.0f, 1.0f), const Vector3f &translation = Vector3f(), const Quaternion &rotation = Quaternion()) :
		m_scale(scale),	
		m_translation(translation),
		m_rotation(rotation) {}

	inline Matrix4f getTransformation()
	{
		Matrix4f scale = Matrix4f().initScale(m_scale);
		Matrix4f translation = Matrix4f().initTranslation(m_translation);
		Matrix4f rotation = m_rotation.toRotationMatrix();

		return rotation * translation * scale;
	}

	inline const Vector3f &getScale() { return m_scale; }
	inline const Vector3f &getTranslation() { return m_translation; }
	inline const Quaternion &getRotation() { return m_rotation; }

	inline void setScale(const Vector3f &scale) { m_scale = scale; }
	inline void setTranslation(const Vector3f &translation) { m_translation = translation; }
	inline void setRotation(const Quaternion &rotation) { m_rotation = rotation; }
protected:
private:
	Vector3f m_scale;
	Vector3f m_translation;
	Quaternion m_rotation;
};

#endif /* defined(__GameEngine3D__transform__) */
