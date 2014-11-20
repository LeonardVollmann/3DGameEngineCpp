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

#ifndef FREE_LOOK_H
#define FREE_LOOK_H

#include "../core/component.h"
#include "../core/math.h"

class FreeLook : public Component
{
public:
	FreeLook(const Vector2f &windowCenter, float sensitivity) :
		m_windowCenter(windowCenter),
		m_sensitivity(sensitivity),
		m_mouseLocked(false) {}
	
	virtual void processInput(const Input &input);
	void rotate(const Vector3f &axis, float angle);
protected:
private:
	Vector2f m_windowCenter;
	float m_sensitivity;
	bool m_mouseLocked;
};

#endif