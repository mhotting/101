#!/bin/sh
make -s;
gcc  -L. -lftprintf main.c -o prog;
./prog;
