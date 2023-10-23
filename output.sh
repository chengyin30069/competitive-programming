#! /bin/bash
clear
echo "Input file:"
echo
cat $1/in.txt
echo
echo "=========================="
echo
declare startTime=`date +%s%N`
$1/out < $1/in.txt > $1/out.txt
declare endTime=`date +%s%N`
delta=`expr $endTime - $startTime`
delta=`expr $delta / 1000000`
cat $1/out.txt
echo
echo "time: $delta ms"
