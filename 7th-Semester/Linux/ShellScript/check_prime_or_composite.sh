#!/bin/sh

#wap to check whether a given number is prime or not   


echo "Enter a number"
read n
(( count = 0 ))
for((i=1; i<=n; i++));
do
if(( n % i == 0 )); then
(( count = count + 1))
fi
done
if(( count > 2)); then
echo "$n is composite"
else
echo "$n is prime"
fi