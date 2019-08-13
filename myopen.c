#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{

	int fd;
	fd = open("text.txt", O_RDWR);
	if(fd == -1)
	{
		perror("open file");
		exit(1);
	}
	int  ret = close(fd);
	//fd = open("hello",O_RDWR | O_CREAT,0777);
	//printf("%d\n",fd);
	fd = open("hello",O_RDWR | O_CREAT | O_EXCL,0777);
	fd = open("text.txt", O_RDWR | O_TRUNC);
	if(ret == 0)
	{
		perror("close file");
		return 0;

	}

	return 0;
}
