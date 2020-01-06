#!/bin/bash
echo "PLease enter the value of n"
read n
X=1
while [ $n -gt 0 ]
do
  X=$((X*n))
  n=$((n-1))
done
echo $X
