#!/bin/sh


#find the largest interger among given 3 integers


echo "Enter first Number"
read n1
echo "Enter second Number"
read n2
echo "Enter third  Number"
read n3
if [ $n1 -gt $n2 -a $n1 -gt $n3 ]; then
echo "$n1 is largest"
elif [ $n2 -gt $n3 ]; then
echo "$n2 is largest"
else
echo "$n3 is largest"
fi

