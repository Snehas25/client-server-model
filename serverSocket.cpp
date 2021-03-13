#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>
#include <bits/stdc++.h>
#define SIZE 1024

using namespace std;
void writeFile(int sockfd)
{
int n;
FILE *fp;
const char *filename = "recv.txt";
char buffer[SIZE];

fp = fopen(filename, "w");
while(1)
{
n = recv(sockfd, buffer ,sizeof(buffer) ,0);
if(n<=0){
break;
return;
}
fprintf(fp, (char *)&buffer,sizeof(buffer));
bzero((char *)&buffer, sizeof(buffer));
}
return;
}

int main(int argc, char *argv[])
{
if(argc!=2)
{
cerr<<"Missing port number"<<endl;
exit(0);
}
int port = atoi(argv[1]);
struct sockaddr_in serverSocket;
bzero((char *)&serverSocket, sizeof(serverSocket));
serverSocket.sin_family = AF_INET;
serverSocket.sin_port = htons(port);
serverSocket.sin_addr.s_addr = htons(INADDR_ANY);

int sockfd  = socket(AF_INET, SOCK_STREAM,0);
if(sockfd <0)
{
cerr<<"Not successful"<<endl;
exit(0);
}

int bindStatus = bind(sockfd, (struct sockaddr*)&serverSocket, sizeof(serverSocket));
if(bindStatus<0)
{
cerr<<"Not successful bind"<<endl;
exit(0);
}
cout<<"Waiting for the client to connect"<<endl;

listen(sockfd,1);

struct sockaddr_in newSocket;
socklen_t newSocketLen = sizeof(newSocket);
int newSocketID = accept(sockfd, (sockaddr*)&newSocket, &newSocketLen);
writeFile(newSocketID);
cout<<"Data written in file successfully"<<endl;
close(newSocketID);
close(sockfd);
}

