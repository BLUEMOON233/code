#include<unistd.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	pid_t pid_1 = 0, pid_2 = 0;
	pid_1 = fork();
	if(pid_1 != 0) pid_2 = fork();
	// printf("%d: %d %d\n",getpid(), pid_1, pid_2);
	if (pid_1 < 0 || pid_2 < 0){
		printf("error in fork!");
	} else if (pid_1 == 0) {
		lockf(1, 1, 0);
		for(int i = 1; i <= 5; i++) {
			srand((unsigned int)time(NULL));
			int tot =  (rand() % 13 + 1) * 1E7;
			for(int cnt = 0; cnt <= tot; cnt++);
			printf("I'm the child process, my pid is %d, count:%d\n", getpid(), i);
		}
		lockf(1, 0, 0);
		exit(0);
	} else if (pid_2 == 0) {
		lockf(1, 1, 0);
		for(int i = 1; i <= 5; i++) {
			srand((unsigned int)time(NULL));
			int tot =  (rand() % 17 + 1) * 1E7;
			for(int cnt = 0; cnt <= tot; cnt++);
			printf("I'm the child process, my pid is %d, count:%d\n", getpid(), i);	
		}
		lockf(1, 0, 0);
		exit(0);
	} else {
		lockf(1, 1, 0);
		for(int i = 1; i <= 5; i++) {
			srand((unsigned int)time(NULL));
			int tot =  (rand() % 23 + 1) * 1E7;
			for(int cnt = 0; cnt <= tot; cnt++);
			printf("I'm the parent process, my pid is %d, count:%d\n", getpid(), i);
		}
		lockf(1, 0, 0);
				
	}
	for(int i = 0; i <= 1E9; i++);
	return 0;
}


