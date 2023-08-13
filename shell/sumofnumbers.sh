echo "Enter Size(N)"
read N

i=1
sum=0

echo "Enter Numbers"
while [ $i -le $N ]
do
  read num           #get number
  sum=$((sum + num)) #sum+=num
  i=$((i + 1))                                
done

echo "sum" $sum
