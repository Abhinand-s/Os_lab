number=1
rows=4

for ((i=1; i<=rows; i++))
do
    for ((j=1; j<=i; j++))
    do
        echo -n "$number "
        number=$((number + 1))
    done
    number=1
    echo
done
