#!/bin/sh
make -s;
gcc -Wall -Werror -Wextra -L. -lftprintf main.c -o prog;
./prog;
