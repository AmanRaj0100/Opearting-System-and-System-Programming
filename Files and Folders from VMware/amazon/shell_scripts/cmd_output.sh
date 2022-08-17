num_of_dirs=`ls -l | grep ^d | wc -l`
num_of_fifos=`ls -l | grep ^p | wc -l`

echo "Number of directories = $num_of_dirs"
echo "Number of fifo files = $num_of_fifos"
