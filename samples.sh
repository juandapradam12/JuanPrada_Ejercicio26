#!/bin/bash

split -n 10 -d --additional-suffix=.txt Pi_2500000.txt parte
for archivo in parte*; do 
./cuenta.x $archivo cuenta_c.txt tiempo_c.txt 
done
rm parte*

split -n 20 -d --additional-suffix=.txt Pi_2500000.txt parte
for archivo in parte*; do 
./cuenta.x $archivo cuenta_c.txt tiempo_c.txt 
done
rm parte*

split -n 50 -d --additional-suffix=.txt Pi_2500000.txt parte
for archivo in parte*; do 
./cuenta.x $archivo cuenta_c.txt tiempo_c.txt 
done
rm parte*

split -n 100 -d --additional-suffix=.txt Pi_2500000.txt parte
for archivo in parte*; do 
./cuenta.x $archivo cuenta_c.txt tiempo_c.txt 
done
rm parte*

python plots.py
