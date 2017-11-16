#!/bin/bash

python ~/rhea-fpga/prog/rhea_comm/measure_tod.py 36.65 -f tod4 -r 100000 -l 1000000
python ~/rhea-fpga/prog/rhea_comm/reader_tod.py tod4 >> tod4.dat
