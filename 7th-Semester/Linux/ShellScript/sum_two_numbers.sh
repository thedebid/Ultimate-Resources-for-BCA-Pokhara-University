#!/bin/sh

#add two numbers and print the result


echo "Enter first number: " 
read num1
echo "Enter second number: " 
read num2
 
sum=$(( $num1 + $num2 ))
 
echo "Sum is: $sum"  