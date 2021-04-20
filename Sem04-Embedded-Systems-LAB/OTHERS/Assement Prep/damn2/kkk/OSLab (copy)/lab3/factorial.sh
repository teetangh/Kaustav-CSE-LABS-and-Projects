echo "Eingresar número"
read number 
fact=1

for((i=2;i<=number;i++))
{
	fact=$((fact * i))
}

echo "Factorial de $number es $fact"
# echo $fact