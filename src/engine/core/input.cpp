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
