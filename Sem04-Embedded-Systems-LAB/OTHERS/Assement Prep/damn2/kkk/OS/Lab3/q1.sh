echo enter a number
read x
c=$(($x%2))

if [ $c = 1 ]
	then
	echo $x is Odd
else
	echo $x is Even

fi
