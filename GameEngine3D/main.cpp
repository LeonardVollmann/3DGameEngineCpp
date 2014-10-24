//
//  main.cpp
//  GameEngine3D
//
//  Created by Leonard Vollmann on 11/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#include "math.h"
#include "window.h"
#include "input.h"
#include "core_engine.h"

#include <iostream>
#include <GL/glew.h>

int main(int argc, const char * argv[]) {
    Window window = Window("3D Game Engine", 800, 600);
    CoreEngine engine = CoreEngine(60, &window);
    engine.start();
    return 0;
}