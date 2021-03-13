INTRODUCTION
This project is based on building a client server model using TCP/IP protocol. It has 5 files. The files testServer.cpp and testClient.cpp
together establishes server and client communication via socket programming. The addition i have made in the project is transfering files. The client side reads a file and sends it to the server. The server side receives the data from the client and saves it in another text file. The files serverSocket.cpp, clientSocket.cpp and send.txt are used in the successful completion of the before stated process.

HOW TO RUN
1.For establishing a communication between client and server-
Open two different terminals. compile the testServer.cpp program in one and provide the port number(e.g., 2000) after compilation. The server will wait for the client to connect. Now, in the other terminal compile the testClient.cpp program and provide the ip address(localhost) and port number(2000). A connection will be established and one can exchange messages between client and server.
2. For reading and sending a text file from client, to server to be stored in another text file
Open two terminals. Compile the serverSocket.cpp program in one and provide the port number(e.g., 2000) after compilation. TThe server will wait for the client to connect. In another terminal, compile the clientSocket.cpp program and provide the ip address(localhost) and port number(2000). The file read by the client is send.txt. On successful completion the same data will be written by server side in a file named recv.txt.

TECH STACK USED
C++, Socket Programming and Computer Networks.

IMPORTANT LOGIC USED

The flow of the code as shown in the picture is important. The IP+port number makes socket unique. 
![img](https://user-images.githubusercontent.com/65017739/111040711-61f06680-845a-11eb-99aa-120bde45a9d4.png)

RESULTS OBTAINED
1. Communication establishment between client and server.
2. File transfer from client to server.

ADDITION TO THE ACM PROJECT

(2 part of HOW TO RUN)
Addition is that the client can now open a text file (in this case 'send.txt'), read it and send it to the server. The server receives data from the client, creates a new text file('in this case recv.txt') and save the data fom the client to this text file.

FUTURE GOALS OF THE PROJECT

Although the addition makes sure that the number of words communicated between client and server do not restrict to one and have increased in number, the future goal of improving this project would be sending and receiving mutiple line data through files and not restricting to all data in one line.

SCREENSHOT SHOWING THE WORKING OF THE PROJECT

![Screenshot from 2021-03-14 04_44_50](https://user-images.githubusercontent.com/65017739/111041107-a977f200-845c-11eb-80cf-93a4b531a4d2.png)
![Screenshot from 2021-03-14 04_48_01](https://user-images.githubusercontent.com/65017739/111041113-af6dd300-845c-11eb-9cd5-192eeff10593.png)
![Screenshot from 2021-03-14 06_06_02](https://user-images.githubusercontent.com/65017739/111041275-6ff3b680-845d-11eb-8f98-e326e8296e1c.png)



 
