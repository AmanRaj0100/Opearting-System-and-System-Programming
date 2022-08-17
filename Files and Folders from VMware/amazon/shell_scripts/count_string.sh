echo "Enter a string:"
read mystr

count_str=`echo $mystr | wc -c`
actual_count=`expr $count_str - 1` #Remember to remove 1 char count because when we i/p keyboards adds one xtra char

echo "Number of caharacters in the string :: $actual_count"
