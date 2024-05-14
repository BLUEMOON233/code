#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define KEY 1122

struct msgform {
	long mtype;
	char mtext[1024];
};


void server() {
	struct msgform msg;
	int msgqid = msgget(KEY, IPC_CREAT | 0666);
	do {
		msgrcv(msgqid, &msg, sizeof(msg.mtext), 0, 0);
		printf("(server)received. message: %s\n", msg.mtext);
	} while (msg.mtype != 1);
	msgctl(msgqid, IPC_RMID, 0);
	exit(0);
}

int main() {
	server();
}