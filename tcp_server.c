// We won't handle to crossplatform, so it won't work on windows. Only on Linux
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main()
{
	// first of all, we should create our "hints" for our server
	// also, we should init structure that containt varuables for out hints
	
	printf("Configuring local variables...\n");
	struct addrinfo hints; // We initzialized structure from <netdb.h> and created block with name "hints"
	memset(&hints, 0, sizeof(hints));

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	printf("Completed!\n");	
	// addrinfo hints 
	// {
	//	int ai_flags;
	//	int ai_family;
	//	int ai_socktype;
	//	int ai_protocol;
	//	char *ai_canonname;
	//	struct sockaddr * ai_addr
	//	struct addrinfo * ai_next
	// }

	// we should create a pointer to struct
	struct addrinfo *bind_address;
	// now we use getaddrinfo() to fill our structere (addrinfo) with new values
	getaddrinfo(0, "8080", &hints, &bind_address); // 8080 is port of the server 
	// now we can create a socket for our server via socket() command
	// So, we create integer valuable that includes socket() function
	printf("Creating socket...\n");
	int socket_l = socket((*bind_address).ai_family, (*bind_address).ai_socktype, 0); // socket()
	printf("Completed!\n");

	printf("Bind...\n"); // Now we should bind ip address to socket by bind() function
	
	int server_bind = bind(socket_l, (*bind_address).ai_addr, (*bind_address).ai_addrlen);
	printf("Completed");
	freeaddrinfo(bind_address); // let's free out memory because we don't want to make memory leaks
	printf("Starting to listen for new connections...\n"); // We are "listening" for incoming requests from users
	
	int server_listener = listen(socket_l, 10); //	listen(int socket, backlog) baclog is maximum queque of users
	
	printf("Completed!\n");
	printf("Connecting...\n");
	struct sockaddr client_addr; // let's create struct for our client
	socklen_t addr_len = sizeof(client_addr); // we initzialize a client address via <sys/socket.h>

	int server_accept = accept(socket_l,&client_addr, &addr_len ); // accept(socket, client address, size of client address)
	printf("Completed!\n");
}
