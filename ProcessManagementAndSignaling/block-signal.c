//In the shell before executing the program: export SLEEP_SECS=5

#include <signal.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char** argv){
	sigset_t blk_grupo;
	sigemptyset(&blk_grupo);
	sigaddset(&blk_grupo,SIGINT);
	sigaddset(&blk_grupo,SIGTSTP);
	sigprocmask(SIG_BLOCK, &blk_grupo,NULL);
	printf("Sleeping\n");
	sleep(atoi(getenv("SLEEP_SECS")));
	sigpending(&blk_grupo);
	if (sigismember(&blk_grupo, SIGINT))
		printf("SIGINT received\n");
	if (sigismember(&blk_grupo, SIGTSTP))
		printf("SIGTSTP received\n");
	sigprocmask(SIG_UNBLOCK, &blk_grupo,NULL);
	printf("Last message. Bye bye.\n");
}
