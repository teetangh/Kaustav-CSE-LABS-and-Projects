# menu program
echo "menu test program"
stop=0

while test $stop -eq 0
do
cat <<ENDOFMENU
1) Print the date
2,3) Print the PWD
4) Exit
ENDOFMENU
echo
echo "Your Choice"
read choice 
echo
case $choice in
	"1")
		date
		echo
		;;
	"2"|"3")
		pwd
		echo
		;;
	"4")
		echo "program terminated"
		echo
		stop=1
		;;
	*)	
		echo "illegal choice"
		echo
		;;
esac
done