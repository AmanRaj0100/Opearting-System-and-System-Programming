#reverse a string program
echo "Enter a string to reverse :: "
read mystr  #Amazon#
len=`echo $mystr|wc -c`
len=$(( $len - 1 ))
echo "Length = $len" #6

while [ $len -gt 0 ]
do 
	ch=`echo $mystr|cut -c$len` #z
	rev=$rev$ch  #rev=noz
	len=`expr $len - 1` #4
done

echo "Reverse String = $rev"
