echo "enter the size"
read n
sum=0
i=1
echo "enter the numbers"
while [ $i -le $n ]
do
   read num
   sum=$((sum + num)) 
   i=$((i + 1))
done
avg=$(bc -l <<< "scale=2; $sum / $n")
echo "average" $avg