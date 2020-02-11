echo the name of this script is $0
echo first argument us $1
echo a list of all the arguments is $*
echo this script places the date into a temporary child
echo called $1.$$
date >$1.$$
ls $1.$$
echo $firstname


 	