# Rename a file by appending _1 to the name

new_name="_1"

for name in $@
do
	if [ -f $name ]
	then
		cp $name $name$new_name
		rm -f $name
		echo "Renamed file: $name$new_name"
	else
		echo "Input valid filename"
	fi
done
