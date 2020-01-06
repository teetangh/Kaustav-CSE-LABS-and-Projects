echo "Enter a string"
read str
n=${#str}
flag=1
for ((i = 0; i < $n; i++)); do
    g=${str:$i:1}
    h=$(($n - $i - 1))
    k=${str:$h:1}

    if [ "$g" == "$k" ]; then
        flag=0
    else
        flag=1
    fi
done

if [ $flag -eq 1 ];
then 
    echo "Not Palin"
else
    echo "Palin"
fi
