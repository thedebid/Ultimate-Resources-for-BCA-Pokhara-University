#!/bin/sh
echo "Enter a number"
read n
for(( i =1;i<=10;i++ )); do
echo "$n * $i = `expr $i \* $n `"
done