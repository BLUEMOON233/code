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
	client();
}