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
	client();
}
