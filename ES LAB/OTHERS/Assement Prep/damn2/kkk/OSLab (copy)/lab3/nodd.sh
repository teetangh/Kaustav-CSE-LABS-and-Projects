echo "Ingrese el valor de N"
read n 
num=1
echo -n "Los primeros $n odd numeros son: "
for((i=1;i<=n;i++))
{
	echo -n "$num "
	num=`expr $num + 2`
}
echo