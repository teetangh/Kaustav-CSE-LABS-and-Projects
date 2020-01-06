#!/bin/bash
echo "Please enter the cofficients of ax^2+bx+c in order"
read a
read b 
read c

D=$(((b*b)-(4*a*c)))

#Real Roots
if [ $D -ge 0 ]
then
d=$(bc<<<"scale=0;sqrt($D)")
echo "The Discriminant is:" 
echo $d
root1=$((((-b+d))/((2*a))))
root2=$((((-b-d))/((2*a))))
echo "The Roots are:"
echo $root1
echo $root2


#Imaginary Roots
elif [ $D -lt 0 ]
then
d=$(bc<<<"scale=0;sqrt($((-D)))")
echo "The Discriminant is:" 
echo $d
real=$((((-b))/((2*a))))
img=$((((d))/((2*a))))
echo "The Roots are:"
echo $real "+i" $img
fi
