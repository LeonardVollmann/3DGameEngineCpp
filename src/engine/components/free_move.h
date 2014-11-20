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

#ifndef FREE_MOVE_H
#define FREE_MOVE_H

#include "../core/component.h"
#include "../core/input.h"
#include "../core/math.h"

class FreeMove : public Component
{
public:
	FreeMove(float speed) :
		m_speed(speed) {}
	
	virtual void processInput(const Input &input);

	void move(const Vector3f &direction, float amount);
protected:
private:
	float m_speed;
};

#endif