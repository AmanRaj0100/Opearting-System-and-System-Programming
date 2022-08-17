#!/bin/bash

echo "Enter a name :: "
read name

if test -f $name
then
	echo "$name is a file"
elif test -d $name
then
	echo "$name is a directory"

elif test -p $name
then
	echo "$name is a fifo file"
else
	echo "$name is a other file"
fi

