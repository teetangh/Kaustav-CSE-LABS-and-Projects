
#/bin/sh

Hello()
{
	echo "Hello Hi $1 $2 $3"
}

# Take user input
echo "Give 3 inputs to say hello"
read a
read b
read c

# invoke Funtion
Hello $a $b $c
