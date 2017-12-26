#! /bin/sh
rm -rf *.log
./cmake.clean
cmake . 
make 

