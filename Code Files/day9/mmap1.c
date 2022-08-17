#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>

int main ()
{
    int fd;
    struct stat s;
    char *mapped;
    int i;

    fd = open ("data.txt", O_RDONLY);

    fstat (fd, & s); 
    printf(" size = %ld\n", s.st_size);

    /* Memory-map the file. */
    mapped = mmap (NULL,4096 , PROT_READ, MAP_PRIVATE, fd, 0);

    /* Now do something with the information. */
    for (i = 0; i < s.st_size; i++) {
	printf("%c",*(mapped+i));
    }
    for (i = 0; i < s.st_size; i++) {
	printf("%c",*(mapped+i));
    }
    for (i = 0; i < s.st_size; i++) {
	printf("%c",*(mapped+i));
    }
    for (i = 0; i < s.st_size; i++) {
	printf("%c",*(mapped+i));
    }
    return 0;
}
