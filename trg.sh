#!/bin/bash

python ~/rhea-fpga/prog/rhea_comm/measure_trg.py 36.65 -f trg13  -r 1000 -t 6.000 -c 5
python ~/rhea-fpga/prog/rhea_comm/reader_tod.py trg13 >> trg13.dat

