#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h> //printf

int main(int argc, char** argv){
	int p_h[2];
	pipe(p_h);
	int h_p[2];
	pipe(h_p);
	//[0] read end, [1] write end
	int pid = fork();
	if(pid == -1){
		perror("fork");
		exit(-1);
	}
	else if (pid == 0){ // Child
		char msg[128];
		close(p_h[1]);
		close(h_p[0]);
		int i=0;
		while (1) {
			read(p_h[0], msg, 128);
			printf("Recibido por el hijo: %s", msg);
			sleep(1);
			if (i== 10){
				write(h_p[1], "q", 1);
				 break;
			}
			else write(h_p[1], "l", 1);
			i++;
		}
	}
	else{ // Parent
		char msg[128];
		close(p_h[0]);
		close(h_p[1]);
		while (1) {
			fgets(msg,128,stdin); // scanf("%s", &msg); can also be used
			write(p_h[1], msg, 128);
			read(h_p[0], msg, 1);
			if (msg[0] == 'q') break;
		}
		
	}
}
