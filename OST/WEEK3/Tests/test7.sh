#!/bin/bash
X=0
while [ $X -le 20 ]
do 
    echo $X
    X=$((X+1))
done

#echo all the command line arguments
while test $# !=0
do 
   echo $1
   #This shift command shifts arguments to the left
   shift
done
       
    
