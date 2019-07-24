#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

static const int SERVER_BUFFER_SIZE = 1024;
static const int CLIENT_INFO_BUFFER_SIZE = 256;

int main(int argc, char* argv[])
{
	//Startup Winsock
	WSADATA data;
	WORD version = MAKEWORD(2, 2);
	int wsOk = WSAStartup(version, &data);
	if(wsOk != 0)
	{
		cout << "Can't start Winsock! " << wsOk << endl;
		return -1;
	}

	//Bind socket to ip address and port
	SOCKET in = socket(AF_INET, SOCK_DGRAM, 0);
	sockaddr_in serverHint;
	serverHint.sin_addr.S_un.S_addr = ADDR_ANY;
	serverHint.sin_family = AF_INET;
	serverHint.sin_port = htons(54000); //Conver from little to big endian

	if(bind(in, reinterpret_cast<sockaddr*>(&serverHint), sizeof(serverHint)) == SOCKET_ERROR)
	{
		cout << "Can't bind socket! " << WSAGetLastError() << endl;
		return -1;
	}

	sockaddr_in client;
	int clientLenght = sizeof(client);
	ZeroMemory(&client, clientLenght);

	char buf[SERVER_BUFFER_SIZE];

	//Enter a loop
	while(true)
	{
		ZeroMemory(buf, SERVER_BUFFER_SIZE);

		//Wait for message
		int bytesIn = recvfrom(in, buf, SERVER_BUFFER_SIZE, 0, reinterpret_cast<sockaddr*>(&client), &clientLenght);
		if(bytesIn == SOCKET_ERROR)
		{
			cout << "Error receiving from client " << WSAGetLastError() << endl;
			continue;
		}

		//Display message and cient info
		char clientIp[CLIENT_INFO_BUFFER_SIZE];
		ZeroMemory(clientIp, CLIENT_INFO_BUFFER_SIZE);

		inet_ntop(AF_INET, &client.sin_addr, clientIp, CLIENT_INFO_BUFFER_SIZE);

		cout << "Message recv from " << clientIp << " : " << buf << endl;
	}

	//Close socket
	closesocket(in);

	//Shutdown winsock
	WSACleanup();

	return 0;
}