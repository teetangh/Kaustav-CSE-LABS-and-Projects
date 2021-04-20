#!/bin/bash
echo "Please enter the value of n"
read n
i=0
temp=$((2*n+1))
while [ $i -lt $temp ]
do
    if [ $(($i%2)) != 0 ]
    then
       echo $i
    fi
i=$((i+1))    

done
