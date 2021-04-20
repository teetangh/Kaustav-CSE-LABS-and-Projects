#!/bin/bash
declare -a teamnames
teamnames[0]="India"
teamnames[1]="England"
teamnames[2]="Nepal"
echo "There are ${#teamnames[*]} teams"
echo "There are ${teamnames[*]}"
unset teamnames[1]
