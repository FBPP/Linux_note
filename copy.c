#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
char buf[2048] = {0};
int main()
{
	int fd_old = open("old.txt",O_RDONLY);
	if(fd_old == -1)
	{
		perror("open error");
		exit(1);

	}
	int fd_new = open("newfile",O_CREAT | O_WRONLY,0777);
	if(fd_new == -1)
	{
		perror("create error");
		exit(1);
	}
	int count = read(fd_old, buf, sizeof(buf));
	if(count == 1)
	{
		perror("read error");
		exit(1);
	}
	while(count)
	{
		int ret = write(fd_new, buf, count);
		printf("write bytes %d/n",ret);
		count = read(fd_old,buf,sizeof(buf));
	}
	close(fd_old);
	close(fd_new);
	return 0;
}
