#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd = open("tempfile",O_CREAT |O_RDWR,0777);
	if(fd == -1)
	{
		perror("error open");
		exit(1);
	}
	unlink("tempfile");
	write(fd,"hello",5);
	lseek(fd, 0,SEEK_SET);
	char buf[10] = {0};
	read(fd ,buf, sizeof(buf));
	write(1,buf,sizeof(buf));
	close(fd);
	
	return 0;
}
