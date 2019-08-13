#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd = open("emptyfile",O_RDWR);
	if(fd == -1)
	{
		perror("open error");
		exit(1);
	}
	int ret = lseek(fd, 0, SEEK_END);
	printf("file length = %d\n", ret);
	ret = lseek(fd, 2000, SEEK_END);
	printf("return value %d\n",ret);
	write(fd,"e",1);
	close(fd);
	return 0;

}
