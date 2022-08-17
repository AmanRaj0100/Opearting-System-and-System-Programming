#!/bin/bash

while [ $# -gt 0 ]
do
	if [ -f $1 ]
	then
		echo "$1 is a file"
	
	elif [ -d $1 ]
	then
		echo "$1 is a directory"

	elif [ -p $1 ]
	then
		echo "$1 is a fifo file"
	else
		echo "$1 is a other file"
	fi
shift
done
echo "bye"
echo "end"

