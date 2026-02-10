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

	printf("Bind process is started...\n");

	// we should create a pointer to our struct
	// this process called "bind"
	struct addrinfo *bind_address;

	// now we use getaddrinfo() to fill our structere (addrinfo) with new values
	getaddrinfo(0, "8080", &hints, &bind_address); // 8080 is port of the server 
	printf("Completed!\n");
	// now we can create a socket for our server via socket() command
	// So, we create integer valuable that includes socket() function
	printf("Creating socket...\n");
	int socket_listener = socket((*bind_address).ai_family, (*bind_address).ai_socktype,(*bind_address).ai_flags); // also, you can use 0 instead of ai_flags (I use to better understanding)
	printf("Completed!\n");

	

}
