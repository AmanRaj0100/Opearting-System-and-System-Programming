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
	case $choice in
		1)
			echo "Adding A Book"
			echo "Adding book logic will be implemented here"
			;;
		2)
			echo "Displaying Books"
			echo "Displaying Books logic will be implemented here"
			;;
		3)
			echo "Searching a Book"
			echo "Searching Books logic will be implemented here"
			;;
		4)	
			echo "Deleting A Book"
			echo "Deleting Books logic will be implemented here"
			;;
		0)
			echo "Exiting Libarary Management Application"
			break
			;;
		*)
			echo "Wrong Choice"
			echo "Please check the menu and enter accordingly"
	esac
done
echo "Bye" 
