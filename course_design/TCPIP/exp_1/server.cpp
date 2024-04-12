#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<WinSock2.h>
#include<stdio.h>
#include<stdlib.h>

// #pragma comment(lib, "ws2_32.lib")

#define DEFAULT_PORT 5050

int main() {
	int iPort = DEFAULT_PORT;
	WSADATA wsaData;
	SOCKET socketListen;
	SOCKET socketAccept;

	int iLen, iSend;
	char buffer[] = "I am a server.";
	struct sockaddr_in serverAddress, clientAddress;

	printf("-----------------------\n");
	printf("server waiting...\n");
	printf("-----------------------\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData)) {
		printf("Fialed to load Winsock.\n");
		return 0;
	}
	socketListen = socket(AF_INET, SOCK_STREAM, 0);
	if (socketListen == INVALID_SOCKET) {
		printf("socket() Fialed: %d\n", WSAGetLastError());
		return 0;
	}

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(iPort);
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(socketListen, (LPSOCKADDR)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
		printf("bind() Failed: %d\n", WSAGetLastError());
		return 0;
	}
	if (listen(socketListen, 5) == SOCKET_ERROR) {
		printf("listen() Failed: %d\n", WSAGetLastError());
		return 0;
	}
	iLen = sizeof(clientAddress);
	while (true) {
		socketAccept = accept(socketListen, (struct sockaddr*)&clientAddress, &iLen);
		if (socketAccept == INVALID_SOCKET) {
			printf("accept() Failed: %d\n", WSAGetLastError());
			break;
		}
		printf("Accepted client IP:[%s], port:[%d]\n",
			inet_ntoa(clientAddress.sin_addr),
			ntohs(clientAddress.sin_port));

		iSend = send(socketAccept, buffer, sizeof(buffer), 0);
		if (iSend == SOCKET_ERROR) {
			printf("send() Failed: %d\n", WSAGetLastError());
			break;
		}
		else if (iSend == 0) {
			break;
		}
		else {
			printf("send() byte: %d\n", iSend);
		}
		closesocket(socketAccept);
	}
	closesocket(socketListen);
	WSACleanup();
	return 0;
}