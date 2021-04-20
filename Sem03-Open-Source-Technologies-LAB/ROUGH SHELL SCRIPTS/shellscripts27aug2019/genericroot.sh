#!/bin/sh
echo please enter any number
read number
reminder=0
while [ $number -ge 10 ]
do
  for (( sum=0 ; $number>0 ; number=`expr $number / 10` ))
  do
    reminder = `expr $number % 10`
    sum=`expr $sum + $reminder`

    if [ $sum -ge 10 ]
    then
      number=$sum
    else
      echo "Generic Root is $sum"
    fi  
  done
done