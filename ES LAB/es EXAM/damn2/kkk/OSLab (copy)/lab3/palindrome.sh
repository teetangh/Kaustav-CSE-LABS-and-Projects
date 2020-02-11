echo "Ingresar la cadena: "
read s
echo $s > temp
rvs="$(rev temp)"
if [ $s = $rvs ]
then
echo "es un palindrom"
else
echo "no es un palindrom"
fi