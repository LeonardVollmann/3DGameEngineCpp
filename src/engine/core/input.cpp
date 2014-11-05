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

#include "input.h"
#include "../rendering/window.h"

#include <SDL2/SDL.h>

Input::Input() :
    m_mouseX(0),
    m_mouseY(0)
{}

void Input::warpMouse(int x, int y) const
{
    SDL_WarpMouseInWindow(m_window->getWindow(), x, y);
}

void Input::setMouseVisible(bool value) const
{
    if (value) {
        SDL_ShowCursor(SDL_ENABLE);
    } else {
        SDL_ShowCursor(SDL_DISABLE);
    }
}
