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

#ifndef CORE_ENGINE_H
#define CORE_ENGINE_H

#include "../rendering/window.h"
#include "../rendering/rendering_engine.h"
#include "game.h"

class CoreEngine
{
public:
    CoreEngine(double fps, Window *window, RenderingEngine *renderingEngine, Game *game);
    
    void start();
    void stop();
    
    inline RenderingEngine *getRenderingEngine() { return m_renderingEngine; }
protected:
private:
    double m_frameTime;
    
    bool m_running;
    
    Window *m_window;
    RenderingEngine *m_renderingEngine;
	Game *m_game;
 
    void update();
    void render();
};

#endif
