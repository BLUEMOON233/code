#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<WinSock2.h>
#include<stdio.h>
#include<stdlib.h>

// #pragma comment(lib, "ws2_32.lib")

#define DEFAULT_PORT 5050
#define DATA_BUFFER 1024

int main(int argc, char *argv[]) {
	WSADATA wsaData;
	SOCKET socketClient;
	int iPort = DEFAULT_PORT;

	int iLen;
	char buffer[DATA_BUFFER];
	struct sockaddr_in serverAddress;
	if (argc < 2) {
		printf("Usage:client [server IP address]\n");
		return 0;
	}
	memset(buffer, 0, sizeof(buffer));
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		printf("Failed to load Winsock.\n");
		return 0;
	}
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(iPort);
	serverAddress.sin_addr.s_addr = inet_addr(argv[1]);
	socketClient = socket(AF_INET, SOCK_STREAM, 0);
	if (socketClient == INVALID_SOCKET) {
		printf("socket() Failed: %d\n", WSAGetLastError());
		return 0;
	}

	if (connect(socketClient, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == INVALID_SOCKET) {
		printf("connect() Failed: %d\n", WSAGetLastError());
		return 0;
	}
	else {
		iLen = recv(socketClient, buffer, sizeof(buffer), 0);
		if (iLen == 0)
			return 0;
		else if (iLen == SOCKET_ERROR) {
			printf("recv() Failed: %d\n", WSAGetLastError());
			return 0;
		}
		printf("recv() data from server:%s\n", buffer);
	}
	closesocket(socketClient);
	WSACleanup();
	return 0;
}