declare -a teamnames
teamnames[0]="India"
teamnames[1]="England"
teamnames[2]="Nepal"
echo "There are ${#teamnames[*]} teams"
echo "There are ${teamnames[*]} teams"
unset teamnames[1]
echo "There are ${teamnames[*]} teams"

