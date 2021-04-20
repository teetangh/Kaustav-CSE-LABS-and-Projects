#!/bin/bash
echo "Please enter a number"
read number
div=$((number%2))
if [ $div = 0 ]
then
echo "even number"
else
echo "odd number"
fi
