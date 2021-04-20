for i in $(seq 1 12); do
   mkdir "WEEK $i"
done
for dir in $(find . -maxdepth 1 -type d) do
   touch "$dir"/name_date.txt
done
