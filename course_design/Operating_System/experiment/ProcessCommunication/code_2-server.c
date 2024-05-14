#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/shm.h>

#define KEY 1122

void server() {
	int shmid = shmget(KEY, 1024, IPC_CREAT | 0666);
	int *addr = (int *)shmat(shmid, 0, 0);
	do {
		*addr = -1;
		while(*addr == -1);
		printf("(server)received: %d\n", *addr);
	} while(*addr != 1);
	shmctl(shmid, IPC_RMID, 0);
	exit(0);
}

int main() {
	server();
}
