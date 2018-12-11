#!/bin/sh
make -s;
gcc main.c -Wall -Werror -Wextra -L. -lftprintf -o prog;
./prog;
