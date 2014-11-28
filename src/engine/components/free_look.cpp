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
			getTransform().rotate(getTransform().getRotation().getRight(), toRadians(mouseDistance.getY()) * m_sensitivity);
		}

		if (mouseDistance.getX() != 0) {
			getTransform().rotate(Vector3f(0.0f, 1.0f, 0.0f), toRadians(mouseDistance.getX()) * m_sensitivity);
		}

		input.warpMouse(m_windowCenter);
	} else {
		if (input.getKey(Input::KEY_LEFT)) {
			getTransform().rotate(Vector3f(0.0f, 1.0f, 0.0f), (m_sensitivity));
		} else if (input.getKey(Input::KEY_RIGHT)) {
			getTransform().rotate(Vector3f(0.0f, 1.0f, 0.0f), -(m_sensitivity));
		}

		if (input.getKey(Input::KEY_UP)) {
			getTransform().rotate(getTransform().getRotation().getRight(), (m_sensitivity));
		} else if (input.getKey(Input::KEY_DOWN)) {
			getTransform().rotate(getTransform().getRotation().getRight(), -(m_sensitivity));
		}
	}

	if (input.getMouseButton(Input::MOUSE_LEFT_BUTTON)) {
		m_mouseLocked = true;
		input.setMouseVisible(false);
		input.warpMouse(m_windowCenter);
	}
}