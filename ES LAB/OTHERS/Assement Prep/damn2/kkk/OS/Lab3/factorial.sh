echo Enter number of fibonacci you want
read n
a=0
b=1
echo first $n fibonacci numbers are
echo $a 
echo $b
n=$(($n-2))
while test $n -gt 0 
do
    c=$(($a+$b))
    echo $c
    temp=$c
    a=$b
    b=$temp
    n=$(($n-1))   
done