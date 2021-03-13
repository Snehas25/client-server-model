#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
if(argc!=2)
{
cerr<<"Missing port number"<<endl;
exit(0);
}
int port = atoi(argv[1]);
char msg[1500];

sockaddr_in serverSocket;
bzero((char *)&serverSocket, sizeof(serverSocket));
serverSocket.sin_family = AF_INET;
serverSocket.sin_port = htons(port);
serverSocket.sin_addr.s_addr = htons(INADDR_ANY);

int serverSocketID = socket(AF_INET, SOCK_STREAM,0);
if(serverSocketID <0)
{
cerr<<"Not successful"<<endl;
exit(0);
}

int bindStatus = bind(serverSocketID, (struct sockaddr*)&serverSocket, sizeof(serverSocket));
if(bindStatus<0)
{
cerr<<"Not successful bind"<<endl;
exit(0);
}
cout<<"Waiting for the client to connect"<<endl;

listen(serverSocketID,1);

sockaddr_in newSocket;
socklen_t newSocketLen = sizeof(newSocket);
int newSocketID = accept(serverSocketID, (sockaddr*)&newSocket, &newSocketLen);

if(newSocketID <0)
{
cerr<<"Not ssuccessfulaccept"<<endl;
exit(0);
}
cout<<"Client connected successfully"<<endl;

while(1)
{
cout<<"Waiting for a message from client"<<endl;
recv(newSocketID, (char*)&msg, sizeof(msg),0);
if(!strcmp(msg,"exit"))
{
cout<<"session terminated"<<endl;
break;
}
cout<<msg<<endl;
string data;
cin>>data;
strcpy(msg, data.c_str());
if(data=="exit")
{
cout<<"Session Terminated"<<endl;
break;
}

send(newSocketID ,(char*)&msg, sizeof(msg),0);
}
close(newSocketID);
close(serverSocketID);
}

