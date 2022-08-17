#reverse a string program
len=`echo $1|wc -c`
len=$(( $len - 1 ))
echo "Length = $len" #6

while [ $len -gt 0 ]
do 
	ch=`echo $1|cut -c$len` #z
	rev=$rev$ch  #rev=noz
	len=`expr $len - 1` #4
done

echo "Reverse String = $rev"
