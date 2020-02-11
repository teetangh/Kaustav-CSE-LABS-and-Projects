echo enter a number
read n
i=0
a=1
while test $i -lt $n
do
	echo $a
	a=$(($a+2))
	i=$(($i+1))
done	