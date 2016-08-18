#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv){
        struct addrinfo *myres = NULL;
        struct addrinfo *res_elem;
        char host[128];
        getaddrinfo(argv[1],NULL, NULL, &myres);
        for(res_elem=myres; res_elem!=NULL; res_elem=res_elem->ai_next){
                getnameinfo(res_elem->ai_addr, res_elem->ai_addrlen, host, 128, NULL, 0, NI_NUMERICHOST);
                printf("Numeric IP: %s\n",host);
                printf("Family: %i\n",res_elem->ai_family);
                printf("Socket type: %i\n", res_elem->ai_socktype);
        }       
        freeaddrinfo(myres);
}
