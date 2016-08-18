#include <sys/types.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <stdlib.h> 
#include <netdb.h> 
#include <time.h> 
#include <sys/select.h> 
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char** argv){
        struct addrinfo* result=NULL;
        struct addrinfo hints;

        memset(&hints, 0, sizeof(hints));
		hints.ai_family = AF_UNSPEC; // IPv4 or IPv6
		hints.ai_socktype = SOCK_DGRAM;// UDP
        hints.ai_flags = AI_NUMERICHOST;
        
        int rc = getaddrinfo(argv[1], argv[2] , &hints, &result);

		// OPEN SOCKET
        int tcp_socket = socket(result->ai_family,result->ai_socktype,0);

        // Establish connection
		connect(tcp_socket,(struct sockaddr *)result->ai_addr, result->ai_addrlen);
        
        freeaddrinfo(result);
       
        char buf[80];
		scanf("%s",buf);
		int bytes=strlen(buf);
		while(!(bytes==1 && buf[0]=='Q')){
				send(tcp_socket, buf, bytes,0);
				bytes = recv(tcp_socket, buf, 79, 0);
				buf[bytes] = '\0'; 
				printf("%s\n",buf);
				scanf("%s",buf);
				bytes=strlen(buf);
		}

	close(tcp_socket);
} 

