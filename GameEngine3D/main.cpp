//
//  main.cpp
//  GameEngine3D
//
//  Created by Leonard Vollmann on 11/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#include "math.h"
#include "window.h"

#include <iostream>
#include <GL/glew.h>

int main(int argc, const char * argv[]) {
    Window window = Window("3D Game Engine", 800, 600);
    while (!window.isClosed()) {
        window.clear(1, 0, 1, 1);
        window.update();
    }
    return 0;
}