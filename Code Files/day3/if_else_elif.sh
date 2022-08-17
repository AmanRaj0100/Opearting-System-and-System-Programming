echo "Library Managemnet Syatem"

while :
do
	echo "1 : Add Book"
	echo "2 : Display Books"
	echo "3 : Search A Book"
	echo "4 : Delete A Book"
	echo "0 : Exit"
	echo "Enter Your Choice :: "
	read choice
	if [ $choice -eq 1 ]
	then
		echo "Adding A Book"
		echo "Adding book logic will be implemented here"
	elif [ $choice -eq 2 ]
	then
		echo "Displaying Books"
		echo "Displaying Books logic will be implemented here"
	elif [ $choice -eq 3 ]
	then
		echo "Searching a Book"
		echo "Searching Books logic will be implemented here"
	elif [ $choice -eq 4 ]

	then
		echo "Deleting A Book"
		echo "Deleting Books logic will be implemented here"
	elif [ $choice -eq 0 ]
	then
		echo "Exiting Libarary Management Application"
		break
	else
		echo "Wrong Choice"
		echo "Please check the menu and enter accordingly"
	fi
done
echo "Bye" 
