#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>
#include <zconf.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netdb.h>

int massHandleSocket[10];
int countClient = 0;

void workClient(int newClient)
{
    char buf[16];
	memset(&buf, 0, sizeof(buf));
	std::cout << "Start listen new client" << std::endl;
        while(true) {
                recv(newClient, buf, sizeof(buf), 0);
                for (int i = 0; i < countClient; i++)
                        send(massHandleSocket[i], buf, sizeof(buf), 0);
		memset(&buf, 0, sizeof(buf));
        }
}

void threadAccept(int& mainSocket)
{
	int newClient;
	while(true) {
		newClient = accept(mainSocket, 0, 0);
		if (newClient < 0) {
			std::cout << "Error Accept" << std::endl;
			close(mainSocket);
			exit(1);
		}
		massHandleSocket[countClient++] = newClient;
		std::cout << "New client" << std::endl;
		if ((countClient-1) % 2 != 0){
			countClient--;
                        continue;
		}
		std::thread t(workClient, newClient);
	}
}

int main()
{
	char buf[1024];
	struct sockaddr_in serverSocket;
	int res;
	int handleSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (handleSocket < 0) {
		std::cout << "Error open socket" << std::endl;
		exit(1);
	}
	memset(&serverSocket, 0, sizeof(serverSocket));

	serverSocket.sin_family = AF_INET;
	serverSocket.sin_port = htons(8000);
	res = inet_pton(AF_INET, "192.168.1.6", &serverSocket.sin_addr);
	if (res < 0) {
		std::cout << "Ошибка при привязка сокета к ip" << std::endl;
		exit(1);
	}
	if (bind(handleSocket, (struct sockaddr*) &serverSocket, sizeof (serverSocket)) == -1) {
		std::cout << "Ошибка связывания" << std::endl;
		close(handleSocket);
		exit(1);
	}
	if (listen(handleSocket, 10) == -1) {
		std::cout << "Ошибка прослушивания" << std::endl;
		close(handleSocket);
		exit(1);
	}

		// Мои операции
	std::thread threadForAccept(threadAccept, std::ref(handleSocket));
	threadForAccept.join();
	return 0;
}
