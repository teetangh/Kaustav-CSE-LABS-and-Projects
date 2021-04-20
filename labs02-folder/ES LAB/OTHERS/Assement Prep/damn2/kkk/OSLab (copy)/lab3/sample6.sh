#sample 6.1
x=0
while [ $x -le 20 ]
do
	echo $x
	x=$(( x + 1))
done

#sample 6.2
while test $# != 0
do
	echo $1
	shift
done
