#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
 	int a,b;
 	fork();
	a = getpid();
 	b = getppid();
 	printf("\nHello World \n pid= %d \n ppid=%d\n",a,b);
 	exit(0);
}
