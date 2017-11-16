#!/bin/bash

file=multiTrg3
mkdir $file

a=0
while [ $a -lt 1000 ]
do
    #touch $file/file$a
	python ~/rhea-fpga/prog/rhea_comm/measure_trg.py 36.65 -f $file/trg$a  -r 1000 -t 6.000 -c 5
	python ~/rhea-fpga/prog/rhea_comm/reader_tod.py $file/trg$a >> $file/trg$a.dat

    a=`expr $a + 1`
done
