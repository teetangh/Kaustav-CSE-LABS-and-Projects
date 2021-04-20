# Take user Input 
stop=0
# echo "Ingrese dos numeros: "
# read a 
# read b

while test $stop -eq 0
do  

echo "Ingrese dos numeros: "
read a 
read b
# Input type of operation 
echo "Introduzca Elección :"	
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read ch 
  
# calulator operations 
case $ch in
  1)res=`echo $a + $b | bc` 
  ;; 
  2)res=`echo $a - $b | bc` 
  ;; 
  3)res=`echo $a \* $b | bc` 
  ;; 
  4)res=`echo "scale=2; $a / $b" | bc`
	;;
  *) echo "Invalid choice"
      res=42069
  ;;
esac
echo "Resultado de la computacion : $res"

echo "Wanna continue (Y/N)?"
read ch2
if [ $ch2 == "N" ]
  then
  stop=1
else
  :
fi
done