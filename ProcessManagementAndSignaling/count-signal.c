#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int num_int = 0;
int num_tstp = 0;
int total =0;

void handler_sigint(){
	num_int ++;
	total++;
}
void handler_sigtstp(){
	num_tstp ++;
	total++;
}

int main(int argc, char** argv){
	struct sigaction act_int, act_tstp;
	act_int.sa_handler = handler_sigint;
	sigaction(SIGINT, &act_int,NULL);
	act_tstp.sa_handler = handler_sigtstp;
	sigaction(SIGTSTP, &act_tstp,NULL);
	while(total < 10){}
	printf("Number of SIGINT: %i\n", num_int);
	printf("Number of SIGTSTP: %i\n", num_tstp);
}
