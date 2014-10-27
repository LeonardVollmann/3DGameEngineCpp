//
//  main.cpp
//  GameEngine3D
//
//  Created by Leonard Vollmann on 11/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#include "./core/core_engine.h"
#include "./rendering/window.h"
#include "./rendering/rendering_engine.h"

int main(int argc, const char * argv[]) {
    Window window = Window("3D Game Engine", 800, 600);
    RenderingEngine renderingEngine = RenderingEngine();
    CoreEngine engine = CoreEngine(60, &window, &renderingEngine);
    engine.start();
    return 0;
}