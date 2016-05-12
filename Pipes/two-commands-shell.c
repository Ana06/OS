#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
	int fds[2];
	pipe(fds);
	// fds[0] write end, fds[1] read end
	int pid = fork();
	if(pid==-1){
		perror("fork");
		exit(-1);
	}
	else if(pid==0){ // Child
		char *arg1 = argv[3];
		char *arg2 = argv[4];
		size_t len = strlen(arg1) + strlen(arg2) + 2;
		char *arg = malloc(len);
		strcpy(arg, arg1);
		strcat(arg, " ");
		strcat(arg, arg2);
		close(fds[1]);
		dup2(fds[0],0);
		system(arg);
	}
	else{ // Parent
		char *arg1 = argv[1];
		char *arg2 = argv[2];
		size_t len = strlen(arg1) + strlen(arg2) + 2;
		char *arg = malloc(len);
		strcpy(arg, arg1);
		strcat(arg, " ");
		strcat(arg, arg2);
		close(fds[0]);
		dup2(fds[1],1);
		system(arg);
	}
}
