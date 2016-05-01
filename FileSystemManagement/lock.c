#include <sys/types.h>//open
#include <sys/stat.h>//open
#include <unistd.h>//fcntl y open
#include <fcntl.h>//fcntl
#include <time.h> //time
#include <string.h> //strlen
#include <stdio.h> //printf

int main(int argc, char** argv){
	char *path=argv[1];
	int fd=open(path,O_WRONLY|O_APPEND|O_CREAT,0666);
	struct flock lock;
	fcntl(fd,F_GETLK,&lock); // Returns flock structure
	if(lock.l_type !=F_UNLCK)
		printf("Locked\n");
	else{
		printf("Unlocked\n");
		lock.l_type=F_WRLCK; // A write lock
		fcntl(fd, F_SETLK, &lock); // The lock is set
		const time_t t =time(0);
		char* hora = ctime(&t); //Current time
		write(fd, hora, strlen(hora));
		sleep(30);
		lock.l_type = F_UNLCK;
		fcntl(fd, F_SETLK, &lock); // We free the lock
	}
	close(fd);
}
