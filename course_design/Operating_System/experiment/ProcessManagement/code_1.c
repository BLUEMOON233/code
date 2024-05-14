#include<unistd.h>
#include<math.h>
#include<stdio.h>
#include<stdbool.h>
int main()
{
	pid_t pid_1 = 0, pid_2 = 0;
	pid_1 = fork();
	if(pid_1 != 0) pid_2 = fork();
	
	// printf("%d: %d %d\n",getpid(), pid_1, pid_2);
	if (pid_1 < 0 || pid_2 < 0){
		printf("error in fork!");
	} else if (pid_1 == 0) {
		// printf("i am the child process, my process id is %d\n", getpid());
		printf("b\n");
		return 0;
	} else if (pid_2 == 0) {
		printf("c\n");
		return 0;
	} else {
		// printf("i am the parent process, my process id is %d\n", getpid());
		printf("a\n");
		int cnt = 1E8;
		while(cnt--);
	}
	//while(true);
	return 0;
}


