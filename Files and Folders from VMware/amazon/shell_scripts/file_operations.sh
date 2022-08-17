echo "My file operations"

if [ $# -eq 2 ]
then
	case $1 in
		"-create")
			echo "creating a file $2"
			touch $2
			;;
		"-delete")
			echo "deleting a file $2"
			rm -f $2
			;;
		"-read")
			echo "read a file $2"
			cat $2
			;;
		"-write")
			echo "writing into a file $2"
			echo "enter data to write"
			#read data
			cat >$2
			;;
		"-append")
			echo "appending into a file $2"
			echo "enter data to append"
			read data
			echo $data >>$2
			;;
		*)	
			echo "Invalid option"
	esac

else
	echo "insufficient arguments"
fi
