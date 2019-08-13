#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	if(argc < 2)
	{
		printf("error: ./a.out filename\n");
		exit(1);
	}
	struct stat st;
	//int ret = stat(argv[1], &st);
	int ret = lstat(argv[1], &st);
	int size = (int)st.st_size;
	printf("file size = %d\n",size);


}
