
#!/bin/sh

NUMS="1 2 3 4 5 6 7"

for NUM in $NUMS
do
  Q=`expr $NUM % 2`
  if [ $Q -eq 0 ]
  then
	echo -n $NUM
	echo " Number is an even number!! "
	continue
  fi
	echo -n $NUM
	echo " Found Odd Number "
done
