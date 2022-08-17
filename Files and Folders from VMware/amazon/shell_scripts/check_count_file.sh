#!/bin/bash

num_dirs=0
num_file=0
num_fifo=0
num_other=0

for name in `ls`
do
	if [ -f $name ]
	then
		num_file=$(( $num_file + 1 ))
	elif [ -d $name ]
	then
		num_dirs=$(( $num_dirs + 1 ))
	elif [ -p $name ]
	then
		num_fifo=$(( $num_fifo + 1 ))
	else
		num_other=$(( $num_other + 1))
	fi
done

echo "Number of files: $num_file"
echo "Number of directories: $num_dirs"
echo "Number of fifo files: $num_fifo"
echo "Number of other files: $num_other"

echo "END"

