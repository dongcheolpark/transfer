#!/bin/sh

if [ ! -d bin/ ]
then
	mdkir bin
fi
cd bin
cmake ..
make