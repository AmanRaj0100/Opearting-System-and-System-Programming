# while loop demo
num=0
until [ $num -gt 50 ]
do
	echo "In while loop"
	echo "num = $num"
	echo "looping"
	num=`expr $num + 1`
	sleep 0.5
done
echo "done"
echo "Bye"
