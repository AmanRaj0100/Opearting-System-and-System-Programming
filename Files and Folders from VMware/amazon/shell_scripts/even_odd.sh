echo "Enter a number ::"
read num

result=$(( $num % 2 ))
 # echo "$result"

if test $result = 0
then
	echo "Even Number"
else
	echo "Odd Number"
fi
