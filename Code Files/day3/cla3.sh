echo "Calculator appliaction"
echo $@
if [ $# -eq 3 ]
then
	res=$(( $1 $2 $3 ))	
	echo "Result = $res"
else  
	echo "Invalid command line arguments"
	echo "enter in following format ./cla3 arg1 operator arg2"
fi
