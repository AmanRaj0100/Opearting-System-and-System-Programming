#check for palindrome
echo "Enter the string ::"
read mystr
len=`echo $mystr | wc -c`
len=$(( $len - 1 ))
echo "Length = $len"
while [ $len -gt 0 ]
do
	ch=`echo $mystr | cut -c$len`
	rev=$rev$ch
	len=`expr $len - 1`
done
echo "Reverse String = $rev"
if test $mystr = $rev
then
	echo "Palindrome!!!"
else
	echo "Not a Palindrome"
fi

