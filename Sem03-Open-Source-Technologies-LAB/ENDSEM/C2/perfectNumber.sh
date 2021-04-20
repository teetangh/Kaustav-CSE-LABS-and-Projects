echo Enter a number
read no
i=1
ans=0
while [ $i -le `expr $no / 2` ]
   do
       if [ `expr $no % $i` -eq 0 ]
       then
          ans=`expr $ans + $i`
       fi
   i=`expr $i + 1`
  done
if [ $no -eq $ans ]
then
echo $no is perfect
else
echo $no is NOT perfect
fi