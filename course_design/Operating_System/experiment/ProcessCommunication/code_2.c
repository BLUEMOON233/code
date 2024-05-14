#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/shm.h>
#include<time.h>

#define KEY 1122

clock_t start, end;

void server() {
	int shmid = shmget(KEY, 1024, IPC_CREAT | 0666);
	int *addr = (int *)shmat(shmid, 0, 0);
	do {
		*addr = -1;
		while(*addr == -1);
		printf("(server)received: %d\n", *addr);
	} while(*addr != 1);
	shmctl(shmid, IPC_RMID, 0);
	
	end = clock();
	double total_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Total time: %f\n", total_time);
	
	exit(0);
}

void client() {
	int shmid = shmget(KEY, 1024, 0666);
	int *addr = (int *)shmat(shmid, 0, 0);
	for(int i = 10; i >= 1; i--) {
		while(*addr != -1);
		printf("(client)sent: %d\n", i);
		*addr = i;
	}
	exit(0);
}

int main() {
	pid_t pid_1 = 0, pid_2 = 0;
	pid_1 = fork();
	if (pid_1 != 0) pid_2 = fork();
	
	start = clock();
	
	if (pid_1 < 0 || pid_2 < 0) {
		printf("Error in fork.\n");
		return 0;
	} else if (pid_1 == 0) {
		server();
	} else if ( pid_2 == 0) {
		client();
	} else {
		wait(0);
		wait(0);
	}
}
