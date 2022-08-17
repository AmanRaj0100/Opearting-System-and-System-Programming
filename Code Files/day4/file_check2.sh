#!/bin/bash
num_dirs=0
num_files=0
num_fifo=0
num_other=0
for name in `ls`
do
	if [ -f $name ]
	then
		echo "$name is a file"
	
	elif [ -d $name ]
	then
		echo "$name is a directory"

	elif [ -p $name ]
	then
		echo "$name is a fifo file"
	else
		echo "$name is a other file"
	fi
done
echo "bye"
echo "end"

