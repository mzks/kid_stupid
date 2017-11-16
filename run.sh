#!/bin/bash

pwd
python ~/rhea-fpga/prog/rhea_comm/measure_swp.py 35.5 37.0 0.01 -f run018
python ~/rhea-fpga/prog/rhea_comm/reader_swp.py run018 >> datfiles/run018.dat

