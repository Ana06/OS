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
	
		// LINK IT TO AN ADDRESS (Allow to receive)
        bind(udp_socket,(struct sockaddr *)result->ai_addr, result->ai_addrlen);
        
        freeaddrinfo(result);
        
        struct sockaddr_storage src_addr;
        socklen_t addrlen = sizeof(src_addr);
        
        char buf[2];
        while (1){
				fd_set set;
				FD_ZERO(&set);
				FD_SET(udp_socket, &set);
				FD_SET(0, &set);
				int fds = select(udp_socket + 1, &set, NULL, NULL, NULL); //Maximum + 1

				time_t act = time(0);
				struct tm* buf_hora;
                buf_hora = localtime(&act);
                
       	        if (FD_ISSET(udp_socket, &set)){
						int bytes = recvfrom(udp_socket, buf, 1, 0,(struct sockaddr *)&src_addr , &addrlen);
						buf[1] = '\0'; 
						char host[NI_MAXHOST];
						char serv[NI_MAXSERV];
						getnameinfo((struct sockaddr *)&src_addr, addrlen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);
						printf("I received %i bytes from %s:%s\n", bytes, host, serv);
				} else {
						scanf("%s", buf);

				}
				if (buf[0] == 't'){
						char s[10];
						strftime(s, 10, "%T", buf_hora); s[9]='\0';
						if (FD_ISSET(udp_socket, &set)) 
							sendto(udp_socket, s, 9, 0,(struct sockaddr *)&src_addr, addrlen); 
						else
								printf("%s\n", s);
				}
				else if (buf[0] == 'd'){
						char s[11];
						strftime(s, 11, "%F", buf_hora); s[10]='\0'; 
						if (FD_ISSET(udp_socket, &set)) 
							sendto(udp_socket, s, 11, 0,(struct sockaddr *)&src_addr, addrlen); 
						else printf("%s\n", s);
				}
				else if (buf[0] != 'q'){
						printf("Invalid comand %s\n", buf);
						if (FD_ISSET(udp_socket, &set)) 
							sendto(udp_socket, buf, 2, 0,(struct sockaddr *)&src_addr, addrlen);
				}
				if (buf[0] == 'q') {
						printf("Exiting \n");
						break;
				}
        }
        close(udp_socket);    
}

