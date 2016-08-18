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
#include <sys/wait.h>

void fin_hijo(int sno){
        int ec;
        pid_t pid=wait(&ec);
        printf("The child has finished %i\n", pid);
}

int main(int argc, char** argv){
        // signal to close children
        struct sigaction sa;
        sa.sa_handler = fin_hijo;
        sa.sa_flags = SA_RESTART; // To restart every interrupted system call
        sigaction(SIGCHLD,&sa,0);
        struct addrinfo* result=NULL;
        struct addrinfo hints;

        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_UNSPEC; // IPv4 or IPv6
        hints.ai_socktype = SOCK_STREAM; // TCP
        hints.ai_flags = AI_NUMERICHOST;

        int rc = getaddrinfo(argv[1], argv[2] , &hints, &result);

		// OPEN SOCKET
        int tcp_socket = socket(result->ai_family,result->ai_socktype,0);
		
		// LINK IT TO AN ADDRESS (Allow to receive)
        bind(tcp_socket,(struct sockaddr *)result->ai_addr, result->ai_addrlen);
        freeaddrinfo(result);
        
        // Change socket state to listen
        listen(tcp_socket,10);

        struct sockaddr_storage src_addr;
        socklen_t addrlen = sizeof(src_addr);  
        
        while(1){
                // Accept connection
                int cliente = accept(tcp_socket,(struct sockaddr *)&src_addr, &addrlen);
                
                char host[NI_MAXHOST];
                char serv[NI_MAXSERV];
                getnameinfo((struct sockaddr *)&src_addr, addrlen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);
                printf("Connection from %s %s\n",host,serv);

                int pid = fork();
                if (pid == 0){ // CHILD
                        close(tcp_socket);
                        char buf[80];
                        int bytes=1;
                        while (bytes>0){
                                bytes = recv(cliente, buf, 79, 0);
                                buf[bytes] = '\0'; 
                                send(cliente, buf, bytes,0);
                        }
                        close(cliente);
                        return 0;
                }
                close(cliente);
        }
        close(tcp_socket);
} 



