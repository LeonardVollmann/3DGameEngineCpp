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

#include "free_look.h"

void FreeLook::processInput(const Input &input)
{
	if (m_mouseLocked) {
		if (input.getKey(Input::KEY_ESCAPE)) {
			m_mouseLocked = false;
			input.setMouseVisible(true);
			return;
		}

		Vector2f mouseDistance = input.getMousePosition() - m_windowCenter;

		if (mouseDistance.getY() != 0) {
			rotate(Vector3f(1.0f, 0.0f, 0.0f).normalized(), mouseDistance.getY() * m_sensitivity);
		}

		if (mouseDistance.getX() != 0) {
			rotate(Vector3f(0.0f, 1.0f, 0.0f).normalized(), mouseDistance.getX() * m_sensitivity);
		}

		input.warpMouse(m_windowCenter);
	}

	if (input.getMouseButton(Input::MOUSE_LEFT_BUTTON)) {
		m_mouseLocked = true;
		input.setMouseVisible(false);
		input.warpMouse(m_windowCenter);
	}
}

void FreeLook::rotate(const Vector3f &axis, float angle)
{
	Quaternion rot = getTransform().getRotation();
	Quaternion newRot = rot.rotate(Quaternion().initFromAxisAngle(axis, angle));
	getTransform().setRotation(newRot);
}