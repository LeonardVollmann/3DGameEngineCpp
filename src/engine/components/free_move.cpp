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

#include "free_move.h"

void FreeMove::processInput(const Input &input)
{
	if (input.getKey(Input::KEY_W)) {
		move(getTransform().getRotation().getForward(), m_speed);
	}
	if (input.getKey(Input::KEY_S)) {
		move(getTransform().getRotation().getBackward(), m_speed);
	}
	if (input.getKey(Input::KEY_A)) {
		move(getTransform().getRotation().getLeft(), m_speed);
	}
	if (input.getKey(Input::KEY_D)) {
		move(getTransform().getRotation().getRight(), m_speed);
	}
}

void FreeMove::move(const Vector3f &direction, float amount)
{
	getTransform().setTranslation(getTransform().getTranslation() + direction * amount);
}