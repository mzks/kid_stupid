#!/bin/bash

file=multiTod1
mkdir $file

a=0
while [ $a -lt 10 ]
do
    #touch $file/file$a
	python ~/rhea-fpga/prog/rhea_comm/measure_tod.py 36.65 -f $file/tod$a -r 100000 -l 1000000
	python ~/rhea-fpga/prog/rhea_comm/reader_tod.py $file/tod$a >>$file/tod$a.dat 

    a=`expr $a + 1`
done
