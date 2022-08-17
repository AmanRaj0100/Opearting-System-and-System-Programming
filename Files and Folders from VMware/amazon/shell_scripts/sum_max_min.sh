# Find sum of the numbers then find max and min among them

sum=0

for num in $@
do
	sum=$(( $num + $sum ))	
done
echo "Total: $sum"
