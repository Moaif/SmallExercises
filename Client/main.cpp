#include <iostream>
#include <WS2tcpip.h>
#include <string>

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
		return  -1;
	}

	//Create a hint structure for the server
	sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(54000);
	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

	//Socket creation
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);

	//Write out to that socket
	string s(argv[1]);
	int sendOk = sendto(out, s.c_str(), s.size() +1, 0, reinterpret_cast<sockaddr*>(&server), sizeof(server));

	if(sendOk == SOCKET_ERROR)
	{
		cout << "That didn't work! " << WSAGetLastError() << endl;
	}

	//Close the socket
	closesocket(out);

	//Close down Winsock
	WSACleanup();
}