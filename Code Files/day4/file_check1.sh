#!/bin/bash


if test -f $1
then
	echo "$1 is a file"
elif test -d $1
then
	echo "$1 is a directory"

elif test -p $1
then
	echo "$1 is a fifo file"
else
	echo "$1 is a other file"
fi

