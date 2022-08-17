export myvar=999
echo "in script1.sh file"
echo "in script1.sh file before script2.sh is invoked myvar = $myvar"
echo "in script1.sh file before script2.sh is invoked"
./scrip2.sh
echo "in script1.sh file after script2.sh is invoked"
echo "in script1.sh file after script2.sh is invoked myvar = $myvar"
echo "end of script1.sh"
echo "bye"
