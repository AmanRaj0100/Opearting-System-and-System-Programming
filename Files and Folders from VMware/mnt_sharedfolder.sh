# Command to mount shared folder

#!/bin/bash

sudo mount -t fuse.vmhgfs-fuse .host:/ /mnt/hgfs -o allow_other

