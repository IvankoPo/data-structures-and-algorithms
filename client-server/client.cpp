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
#include <mutex>
std::mutex m;
void listenMessage(int& sock)
{
	char buf[16];
	int err;
	memset(&buf, 0, sizeof(buf));
	while(true) {
		m.lock();
		recv(sock, buf, sizeof(buf), 0);
		std::cout << buf << std::endl;
		m.unlock();
	}
}

void sendMessage(int& sock)
{
	char buf[16];
	memset(&buf, 0, sizeof(buf));
	int err;
	while(true) {
		m.lock();
		gets(buf);
		err = send(sock, buf, sizeof(buf), 0);
		if (err < 0) {
                        std::cout << "Error send" << std::endl;
                        close(sock);
                        exit(1);
                }
		m.unlock();
	}
}

int main()
{
	int sockForSend, sockForRecv;
	struct sockaddr_in clientSocket;
	sockForSend = socket(AF_INET, SOCK_STREAM, 0);
	sockForRecv = socket(AF_INET, SOCK_STREAM, 0);
	if (sockForSend == -1 || sockForRecv == -1){
		std::cout << "Ошибка при создании сокета" << std::endl;
		exit(1);
	}
	
	memset(&clientSocket, 0, sizeof(clientSocket));
	
	clientSocket.sin_family = AF_INET;
	clientSocket.sin_port = htons(8000);
	int err = inet_pton(AF_INET, "192.168.1.6", &clientSocket.sin_addr);

	if (err < 0){
		std::cout << "Не удалось привязать сокет к ip" << std::endl;
		close(sockForSend);
		close(sockForRecv);
		exit(1);
	}

	if (connect(sockForSend, (struct sockaddr*) &clientSocket, sizeof(clientSocket)) < 0 ){
		std::cout << "Ошибка при соединении к серверу" << std::endl;
		close(sockForSend);
		exit(1);
	}

	if (connect(sockForRecv, (struct sockaddr*) &clientSocket, sizeof(clientSocket)) < 0 ){
                std::cout << "Ошибка при соединении к серверу" << std::endl;
                close(sockForRecv);
                exit(1);
        }
	
	std::thread threadForSend(sendMessage, std::ref(sockForSend));
	std::thread threadForRecv(listenMessage, std::ref(sockForRecv));
	threadForSend.join();
	threadForRecv.join();
	close(sockForSend);
	close(sockForRecv);
	return 0;
}

