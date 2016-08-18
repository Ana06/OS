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

int main(int argc, char** argv){
		struct addrinfo* result=NULL;
		struct addrinfo hints;

		memset(&hints, 0, sizeof(hints));
		hints.ai_family = AF_UNSPEC; // IPv4 or IPv6
		hints.ai_socktype = SOCK_DGRAM;// UDP
		hints.ai_flags = AI_NUMERICHOST;

		int rc = getaddrinfo(argv[1], argv[2] , &hints, &result);

		// OPEN SOCKET
		int udp_socket = socket(result->ai_family,result->ai_socktype,0);
		
		struct sockaddr_storage src_addr;
		socklen_t addrlen = sizeof(src_addr);
		memcpy((void*) &src_addr, result->ai_addr, result->ai_addrlen);
		
		freeaddrinfo(result);

		char buf[2];
		char buf_read[80];
		while (1){
				scanf("%s",buf);
				sendto(udp_socket,buf, 1, 0, (struct sockaddr*)&src_addr,addrlen);
				int bytes = recvfrom(udp_socket,buf_read, 79, 0, (struct sockaddr *) &src_addr,&addrlen);
				buf_read[bytes]='\0';
				printf("%s\n",buf_read);
		}
		close(udp_socket);
}

