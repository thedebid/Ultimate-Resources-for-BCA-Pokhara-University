#!bin/bash
echo "Enter a number"
read n
(( result = $n % 2  ))
if [ $result -eq 0 ]; then
echo "$n is even"
else 
echo "$n is odd"
fi 