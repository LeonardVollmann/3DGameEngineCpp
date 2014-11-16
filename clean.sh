#!/bin/bash

rm cmake_install.cmake
rm CMakeCache.txt
if [ -d "CMakeFiles/" ]; then
	cd ./CMakeFiles
	rm -r ./*
	cd ..
	rmdir ./CMakeFiles
fi
cd ./build
rm -r ./*
