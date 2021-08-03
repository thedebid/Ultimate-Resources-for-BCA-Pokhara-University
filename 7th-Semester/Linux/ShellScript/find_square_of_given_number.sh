#!bin/bash
echo "Enter a number"
read n
(( result = $n * $n ))
echo "Square of given number is $result"