#!/bin/bash

#Library Menu Format:

while : 
do

echo "                    "
echo "Library Management Sysytem"
echo "==============================="
echo " a> add_books;; "
echo " b> find_books;; "
echo " c> edit_books;; "
echo " d> remove_books;; "
echo " e> view_books;; "
echo " f> quit "
echo "==============================="
echo "                    "
echo "Enter your request:: "
echo "Options for the request: a/b/c/d/e/f"

#Read user request:

read req

# Uses case esac statement to access the options of the menu

	case $req in
		"a")
			echo "                    "
			echo "Add the details of the book in the mentioned format:"
			echo "Format: Book Name,Author_1,Publisher,Total Copies"
			echo "                                "
			read new_book
			echo $new_book | cat >> inventory.txt  # Reads the book details and append it to the inventory.txt file
			;;
		"b")
			echo "                    "
			echo "Search the library's iventory for a book:"
			read find_book
			grep -iF $find_book inventory.txt   # Uses grep with -inF means the entered book can be case insensitive with fixed pattern.								
			;;
		"c")
			echo "                    "
			echo "read a file $2"
			cat $2
			;;
		"d")
			echo "                    "
			echo "Remove the book from the library's inventory"
			echo "Enter the details of the book:"
			read remove_book
			var=`grep -iF $remove_book inventory.txt`
			echo "This book will be removed from the inventory:"
			echo "$var"
			echo "Are you sure? Confirm: Y/N"
			read confirm
			if [ $confirm == "Y" ] || [ $confirm == "y" ]
			then
				grep -ivF $remove_book inventory.txt | cat >> updated_inventory.txt
				rm inventory.txt
				cp updated_inventory.txt inventory.txt
				rm updated_inventory.txt
				echo "Deleted"
			elif [ $confirm == "N" ] || [ $confirm == "n" ]
			then
				echo "Retained"
			else
				echo "Enter valid option"
			fi
			;;
		"e")
			echo "                    "
			echo "Displaying the books in the library:"
			echo "                         "
			cat inventory.txt
			;;
		"f")
			echo "                    "
			echo "Exiting Library Management System"
			break
			;;	
		*)
			echo "Invalid request"
			echo "Check the menu again and select the option."
	esac
done





