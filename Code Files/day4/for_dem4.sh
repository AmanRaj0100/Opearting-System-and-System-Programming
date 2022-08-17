#!/bin/bash
echo  "demo for loop"
for var in `ls`
do
	if [ -s $var ]
	then
		echo "$var size is greater then 0"
	else
		echo "$var size is equal to 0"
		rm -f $var
	fi
done

echo "bye"
echo "end"
