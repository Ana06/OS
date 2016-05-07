#include <sched.h> //sched
#include <stdio.h> //printf
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv){
	int i=sched_getscheduler(0);
	char* sched;
        switch(i){
                case SCHED_FIFO: sched = "SCHED_FIFO";break;
                case SCHED_RR: sched = "SCHED_RR";break;
                case SCHED_OTHER: sched = "SCHED_OTHER"; break;
                default: sched="OTRA";break;
        }
	int my_pid=getpid();
	printf("%i scheduling policy: %s\n", my_pid, sched);
	struct sched_param p;
	sched_getparam(0, &p);
	printf("%i scheduling priority: %i\n", my_pid, p.sched_priority);
	printf("Priotiry maximun value: %i\n",sched_get_priority_max(i));
	printf("Priority minimum value: %i\n",sched_get_priority_min(i));
}
