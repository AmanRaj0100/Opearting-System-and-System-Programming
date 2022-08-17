# while loop demo
while :
do
	echo "Enter a String and quit to stop :: "
	read mystr
	if test $mystr = 'quit' 
	then
		echo "quiting"
		break
	else
		len=`echo $mystr | wc -c`
		len=`expr $len - 1`
		if [ $len -ge 20 ]
		then 
			echo "String is = $mystr"
			echo "length = $len"
			echo $mystr|tr a-z A-Z
		else
			continue
		fi
	fi

done
echo "done"
echo "Bye"
