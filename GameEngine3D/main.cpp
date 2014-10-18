//
//  main.cpp
//  GameEngine3D
//
//  Created by Leonard Vollmann on 11/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#include <iostream>
#include "math.h"

int main(int argc, const char * argv[]) {
    Vector3f v = Vector3f(2, 3, 4);
    Vector3f f = Vector3f(1, 4, 2);
    Matrix4f m = Matrix4f().initIdentity();
    Quaternion q = Quaternion(0, 1, 0, toRadians(90.0f));
    v = v.rotate(q);
//    v = v.cross(f);
//    v *= 3;
//    v += f;
//    v = v.normalized();
    std::cout << v.getX() << ", " << v.getY() << ", " << v.getZ() << std::endl;
    
    std::cout << (m[1][1]) << std::endl;
    return 0;
}