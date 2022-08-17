#if flow control statement

echo "Enter a string :: "
read mystr #555

if test $mystr = "amazon"
then
	echo "inside if block"
	echo "mystring is amazon"
	echo "mystr = $mystr"
	echo "end of mustr"
else
	echo "inside else block"
	echo "mystr is not amazon"
	echo "mystr = $mystr"
	echo "end of else"
fi

echo "end"
echo "bye"

