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

#include "engine/core/core_engine.h"
#include "engine/rendering/window.h"
#include "engine/rendering/rendering_engine.h"
#include "game/test_game.h"

int main(int argc, const char * argv[]) {
    Window window("3D Game Engine", 800, 600);
    RenderingEngine renderingEngine = RenderingEngine();
	TestGame game;
    CoreEngine engine = CoreEngine(60, &window, &renderingEngine, &game);
    engine.start();
    return 0;
}