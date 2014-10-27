#!/bin/bash

rm cmake_install.cmake
rm CMakeCache.txt
cd ./CMakeFiles
rm -r ./*
cd ../
rmdir ./CMakeFiles
cd ./build
rm -r ./*