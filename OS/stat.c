#include<stdio.h>
#include<sys/stat.h>
int main()
{
	struct stat sfile;
	stat("hello.txt",&sfile);
	printf("\nst_mode = %o",sfile.st_mode);
	printf("\nFile st_uid %d\n",sfile.st_uid);
	printf("\nFile st_size bytes %ld\n",sfile.st_size);
	return 0;
}
