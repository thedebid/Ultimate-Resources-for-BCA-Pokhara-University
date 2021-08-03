#!bin/bash

echo "Enter two numbers"
read a
read b

if [ $a -gt $b ]; then
echo "$a is greatest"
else
echo "$b is greatest"
fi
