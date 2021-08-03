#!/bin/sh


#find the largest among given 4 numbers


echo "Enter first Number"
read a
echo "Enter second Number"
read b
echo "Enter third  Number"
read c
echo "Enter fourth Number" 
read d
if [ $a -gt $b -a $a -gt $c -a $a -gt $d ]; then
echo "$a is largest"
elif [ $b -gt $c -a $b -gt $d ]; then
echo "$b is largest"
elif [ $c -gt $d ]; then
 echo "$c is largest"
else
echo "$d is largest"
fi

