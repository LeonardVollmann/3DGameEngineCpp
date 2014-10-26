#!/bin/bash

cd ./build
cmake -DCMAKE_BUILD_TYPE="Debug" ../
cd ..
make -j 4