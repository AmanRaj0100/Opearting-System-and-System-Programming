# while loop demo
echo "Enter stop point"
read val
num=0
while [ $num -le 50 ]
do
	echo "In while loop"
	echo "num = $num"
	if [ $num -eq $val ]
	then
		break
	fi
	echo "looping"
	num=`expr $num + 1`
	sleep 0.5
done
echo "done"
echo "Bye"
