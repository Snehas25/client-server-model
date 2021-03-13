#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <bits/stdc++.h>
#define SIZE 1024
using namespace std;

void sendFile(FILE *fp, int sockfd)
{
int n;
char data[SIZE] = {0};
while(fgets((char *)&data,sizeof(data), fp)!= NULL)
{
if(send(sockfd, (char *)&data, sizeof(data),0)<0);
{
break;
exit(0);
}
bzero((char *)&data, SIZE);
}
}

int main(int argc, char *argv[])
{
if(argc!=3)
{
cerr<<"Missing hostname and port number\n";
exit(0);
}
char* serverName = argv[1];
int port = atoi(argv[2]);
FILE *fp;
const char *filename = "send.txt";

struct hostent* host = gethostbyname(serverName);
sockaddr_in clientSocket;
clientSocket.sin_family = AF_INET;
clientSocket.sin_port = htons(port);
clientSocket.sin_addr = **(struct in_addr**)host->h_addr_list;
int clientSocketID = socket(AF_INET, SOCK_STREAM, 0);
int status = connect(clientSocketID, (sockaddr*) &clientSocket, sizeof(clientSocket));
if(status<0)
{
cout<<"Error connecting\n";
exit(0);
}
cout<<"Successful connection\n";

fp = fopen(filename, "r");
if(fp== NULL)
{
cerr<<"Error in reading file"<<endl;
exit(0);
}
sendFile(fp, clientSocketID);
cout<<"File data sent successfully"<<endl;
cout<<"Closing the connection"<<endl;
close(clientSocketID);
}
