echo "Enter num1 :: "
read num1 #123
echo  "Enter num2 :: "
read num2 #345
echo  "Enter num3 :: "
read num3 #456

num4=$(( $num1 + $num2 + $num3 ))
#num4=`expr $num4 + $num3`
echo "Num1 = $num1"
echo "Num2 = $num2"
echo "Num3 = $num3"
echo "Num4 = $num4"
