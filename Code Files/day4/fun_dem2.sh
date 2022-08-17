#!/bin/bash

myMax()
{
	if [ $1 -gt $2 ]
	then
		return $1
	elif [ $1 -eq $2 ]
	then
		return $1
	else
		return $2
	fi
}

echo "in main script"
myMax 10 10
echo "return value $?"
echo "end"
echo "Bye"

