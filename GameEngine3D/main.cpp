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

#include <iostream>
#include <GL/glew.h>

int main(int argc, const char * argv[]) {
    Window window = Window("3D Game Engine", 800, 600);
    window.getInput().setMouseVisible(false);
    while (!window.isClosed()) {
        window.clear(1, 0, 1, 1);
        window.update();
//        if (window.getInput().getKey(Input::KEY_A)) {
//            std::cout << "Pressed A!" << std::endl;
//        }
        std::cout << window.getInput().getMousePosition()[0] << ", " << window.getInput().getMousePosition()[1] << std::endl;
        window.getInput().warpMouse(400, 300);
    }
    return 0;
}