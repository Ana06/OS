#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char* me;
void handler(){
	exit(0);
}

void my_alarm(){
        unlink(me);
        exit(0);        
}

int main(int argc, char** argv){
	struct sigaction act, act_alarm;
	act.sa_handler = handler;
	sigaction(SIGUSR1, &act,NULL);
	act_alarm.sa_handler = my_alarm;
	sigaction(SIGALRM, &act_alarm,NULL);
	me = argv[0];
	alarm(atoi(argv[1]));
	printf("Self-destructing...\n");
	while(1){}
}
