echo "enter number"
read n
s=$n
while [ $s -gt 9 ]
do
s=0
   while [ $n -gt 0 ]
   do
   	s=`expr $s + $n % 10`
   	n=`expr $n/10`
   done
n=$s
done
echo $s