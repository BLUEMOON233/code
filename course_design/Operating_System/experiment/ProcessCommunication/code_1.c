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
	int msgqid = msgget(KEY, IPC_CREAT | 0666);
	struct msgform msg;
	do {
		msgrcv(msgqid, &msg, sizeof(msg.mtext), 0, 0);
		printf("(server)received. message: %s\n", msg.mtext);
	} while (msg.mtype != 1);
	msgctl(msgqid, IPC_RMID, 0);
	exit(0);
}

void client() {
	int msgqid = msgget(KEY, 0666);
	for (int i = 10; i >= 1; i--) {
		struct msgform msg;
		msg.mtype = i;
		strcpy(msg.mtext, "hello world!");
		printf("(client)sent\n");
		msgsnd(msgqid, &msg, sizeof(msg.mtext), 0);
	}
	exit(0);
}

int main() {
	pid_t pid_1 = 0, pid_2 = 0;
	pid_1 = fork();
	if (pid_1 != 0) pid_2 = fork();

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