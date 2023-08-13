echo "enter two numbers"
read num1
read num2
temp=$num1
num1=$num2
num2=$temp
echo "after swapping"
echo $num1 $num2