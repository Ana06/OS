#include <unistd.h>
#include <sched.h>

int main(int argc, char** argv){
	struct sched_param p;
	sched_getparam(0, &p);
	if (argc < 1 || argv[1] ==NULL) 
		p.sched_priority=sched_get_priority_max(SCHED_FIFO);
	else
		p.sched_priority=atoi(argv[1]);
	sched_setscheduler(0, SCHED_FIFO,&p);
 	execlp("/bin/sh","/bin/sh",NULL);
}
