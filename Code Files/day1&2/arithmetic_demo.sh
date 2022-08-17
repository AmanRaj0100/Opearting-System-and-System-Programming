echo "Enter num1 :: "
read num1 #123
echo  "Enter num2 :: "
read num2 #345

num3=`expr $num1  $num2` #123+345

echo "Num1 = $num1"
echo "Num2 = $num2"
echo "Num3 = $num3"
