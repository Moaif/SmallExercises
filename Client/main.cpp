#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include <ctime>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

#define DEFAULT_PORT "27015"

static const float CONECTION_WAIT_TIME = 5.0f;
static const int SERVER_MSG_BUFFER = 128;

int main(int argc, char* argv[])
{
	// Validate the parameters
	if(argc != 2)
	{
		printf("usage: %s server-name\n", argv[0]);
		return 1;
	}

	//Startup Winsock
	WSADATA data;
	WORD version = MAKEWORD(2, 2);
	int wsOk = WSAStartup(version, &data);
	if(wsOk != 0)
	{
		cout << "Can't start Winsock! " << wsOk << endl;
		return  1;
	}

	struct addrinfo hints;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;

	// Resolve the server address and port
	struct addrinfo* result;
	wsOk = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
	if(wsOk != 0)
	{
		printf("getaddrinfo failed with error: %d\n", wsOk);
		WSACleanup();
		return 1;
	}

	//Create socket & try to conect to UDP server
	SOCKET out;
	char buf[SERVER_MSG_BUFFER];
	bool conected = false;
	DWORD timeout = CONECTION_WAIT_TIME * 1000;
	for(; result != NULL; result = result->ai_next)
	{
		out = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
		if(out == INVALID_SOCKET)
		{
			printf("socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			return 1;
		}

		//Send join request
		ZeroMemory(buf, SERVER_MSG_BUFFER);
		buf[0] = '1';
		int sendOk = sendto(out, buf, SERVER_MSG_BUFFER, 0, result->ai_addr, static_cast<int>(result->ai_addrlen));

		if(sendOk == SOCKET_ERROR)
		{
			cout << "That didn't work! " << WSAGetLastError() << endl;
		}

		//Wait for the server reply, otherwise its not conected
		setsockopt(out, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof timeout);

		wsOk = recv(out, buf, SERVER_MSG_BUFFER, 0);

		if(wsOk == SOCKET_ERROR)
		{
			int error = WSAGetLastError();
			if(error != WSAEWOULDBLOCK && error != WSAECONNRESET)
			{
				cout << "Waiting for conection returned SOCKET_ERROR" << WSAGetLastError() << endl;
			}

		}
		//If the buffer is not empty
		if(buf[0] != '\0')
		{
			if(buf[0] == 1)// 1 is for join , 2 for input(should be managed with enums
			{				
				cout << "Conected to server" << endl;
				conected = true;
				break;
			}
		}		
	}

	if(!conected)
	{
		cout << "No response from the server, not possible to connect" << endl;
		WSACleanup();
		return 1;
	}

	//Write out to that socket
	string s("");
	do{
		cout << "Enter text to server: ";
		getline(cin, s);
		if(s == "exit")
		{
			break;
		}
		s = '2' + s;//Add the type value for input

		int sendOk = sendto(out, s.c_str(), s.size() + 1, 0, result->ai_addr, static_cast<int>(result->ai_addrlen));

		if(sendOk == SOCKET_ERROR)
		{
			cout << "That didn't work! " << WSAGetLastError() << endl;
		}
	}while(true);

	
	freeaddrinfo(result);

	//Close the socket
	closesocket(out);

	//Close down Winsock
	WSACleanup();
}