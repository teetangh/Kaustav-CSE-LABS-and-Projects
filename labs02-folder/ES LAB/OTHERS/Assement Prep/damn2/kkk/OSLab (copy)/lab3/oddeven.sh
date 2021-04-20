echo "Ingresar número"
read number 
rem=`expr $number % 2`

# echo "$rem"
if [ $rem == 1 ]
then
echo "$number es un número impar(odd)"
else
echo "$number es un número par(even)"
fi