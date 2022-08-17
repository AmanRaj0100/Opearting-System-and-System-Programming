#!/bin/bash

myMax()
{
	if [ $1 -gt $2 ]
	then
		echo "$1 is greater"
	else
		echo "$2 is greater"
	fi
}

echo "in main script"
myMax 30 20
echo "end"
echo "Bye"

