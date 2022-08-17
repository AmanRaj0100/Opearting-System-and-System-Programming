num_of_dirs=`ls -l |grep ^d | wc -l`
num_of_fifos=`ls -l|grep ^p |wc -l`

echo "number of directories = $num_of_dirs"
echo "number of fifo files = $num_of_fifos"
