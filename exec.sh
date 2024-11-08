#!/bin/bash
clear
g++ -O2 -Wall -Wextra -Wshadow "$1" -o out
echo Input:
cat in.txt
echo
echo "======================================"
echo 
./out < in.txt
