#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

#define DEFAULT_PORT "27015"

static const int SERVER_BUFFER_SIZE = 1024;
static const int CLIENT_INFO_BUFFER_SIZE = 256;
static const int SERVER_ACCEPT_MSG_BUFFER = 128;

int main(int argc, char* argv[])
{
	//Startup Winsock
	WSADATA data;
	WORD version = MAKEWORD(2, 2);
	int wsOk = WSAStartup(version, &data);
	if(wsOk != 0)
	{
		cout << "Can't start Winsock! " << wsOk << endl;
		return 1;
	}

	struct addrinfo hints;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	struct addrinfo *result;
	wsOk = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if(wsOk != 0)
	{
		printf("getaddrinfo failed with error: %d\n", wsOk);
		WSACleanup();
		return 1;
	}

	// Create a SOCKET for connecting to server
	SOCKET in = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if(in == INVALID_SOCKET)
	{
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	if(bind(in, result->ai_addr, static_cast<int>(result->ai_addrlen)) == SOCKET_ERROR)
	{
		cout << "Can't bind socket! " << WSAGetLastError() << endl;
		return 1;
	}

	freeaddrinfo(result);

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

		char msgType = buf[0];
		char_traits<char>::move(buf-1,buf, SERVER_BUFFER_SIZE);

		switch(msgType)
		{
			case '1'://join
				char accept[SERVER_ACCEPT_MSG_BUFFER];
				ZeroMemory(accept, SERVER_ACCEPT_MSG_BUFFER);
				accept[0] = 1;
				wsOk = sendto(in, accept, SERVER_ACCEPT_MSG_BUFFER, 0, reinterpret_cast<sockaddr*>(&client), sizeof(client));

				if(wsOk == SOCKET_ERROR)
				{
					cout << "Server failed sending acceptance message " << WSAGetLastError() << endl;
				}
				break;
			case '2'://input
				//Display message and cient info
				char clientIp[CLIENT_INFO_BUFFER_SIZE];
				ZeroMemory(clientIp, CLIENT_INFO_BUFFER_SIZE);

				inet_ntop(AF_INET, &client.sin_addr, clientIp, CLIENT_INFO_BUFFER_SIZE);

				cout << "Message recv from " << clientIp << " : " << buf << endl;
				break;
			default:
				break;
		}
		
	}

	//Close socket
	closesocket(in);

	//Shutdown winsock
	WSACleanup();

	return 0;
}