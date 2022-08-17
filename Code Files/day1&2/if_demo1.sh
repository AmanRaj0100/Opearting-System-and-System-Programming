#if flow control statement

echo "Enter a number :: "
read num1 #555

if test $num1 -eq 100
then
	echo "inside if block"
	echo "num1 is equal to 100"
	echo "num1 = $num1"
	echo "end of if"
else
	echo "inside else block"
	echo "num1 is  not equal to 100"
	echo "num1 = $num1"
	echo "end of else"
fi

echo "end"
echo "bye"

