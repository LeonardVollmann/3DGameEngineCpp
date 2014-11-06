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

#ifndef WINDOW_H
#define WINDOW_H

#include "../core/input.h"

#include <string>
#include <SDL2/SDL.h>

class Input;

class Window
{
public:
    Window(const std::string &title, unsigned int width, unsigned int height);
    virtual ~Window();
    
    void update();
    void clear(float r, float g, float b, float a);
    
    inline bool isClosed()               const { return m_closed; }
    inline const std::string &getTitle() const { return m_title; }
    inline unsigned int getWidth()       const { return m_width; }
    inline unsigned int getHeight()      const { return m_height; }
    inline float getAspectRatio()        const { return (float)m_width / (float)m_height; }
    inline SDL_Window *getWindow()       const { return m_window; }
    inline Input &getInput()       		 { return m_input; }
protected:
private:
    std::string  m_title;
    unsigned int m_width;
    unsigned int m_height;
    
    SDL_Window   *m_window;
    SDL_GLContext m_glContext;
    
    Input m_input;
    
    bool m_closed;
};

#endif
