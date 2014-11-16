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

#include "window.h"

#include <GL/glew.h>
#include <iostream>

Window::Window(const std::string &title, unsigned int width, unsigned int height) :
    m_title(title),
    m_width(width),
    m_height(height),
    m_closed(false)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);



    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    m_glContext = SDL_GL_CreateContext(m_window);
    m_closed = false;
    
    glewExperimental = GL_TRUE;
    GLenum status = glewInit();
    if (status != GLEW_OK) {
        std::cerr << "ERROR: Glew failed to initialize" << std::endl;
    }
    
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    
    m_input.setWindow(this);
}

Window::~Window()
{
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Window::update()
{
    SDL_GL_SwapWindow(m_window);
    
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            m_closed = true;
        } else if (e.type == SDL_KEYDOWN) {
            int key = e.key.keysym.scancode;
            
            m_input.setKeyDown(key, true);
            m_input.setKeyUp(key, false);
            m_input.setKey(key, true);
        } else if (e.type == SDL_KEYUP) {
            int key = e.key.keysym.scancode;
            
            m_input.setKeyDown(key, false);
            m_input.setKeyUp(key, true);
            m_input.setKey(key, false);
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            int button = e.button.button;
            
            m_input.setMouseDown(button, true);
            m_input.setMouseUp(button, false);
            m_input.setMouseButton(button, true);
        } else if (e.type == SDL_MOUSEBUTTONUP) {
            int button = e.button.button;
            
            m_input.setMouseDown(button, false);
            m_input.setMouseUp(button, true);
            m_input.setMouseButton(button, false);
        } else if (e.type == SDL_MOUSEMOTION) {
            m_input.setMousePosition(e.motion.x, e.motion.y);
        }
    }
}

void Window::clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
