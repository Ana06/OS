#include <stdio.h> //printf
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>

int main(int argc, char** argv){
	printf("Id: %i\n",getpid());
	printf("Group id: %i\n",getpgid(0));
	printf("Session id: %i\n",getsid(0));
	struct rlimit rlim;
	getrlimit(RLIMIT_NOFILE,&rlim);
	printf("Number of files that can open the process: %i\n",rlim.rlim_cur); //soft limit, también hay un hard limit (rlimit_max)
	printf("Actual directory: %s\n",getcwd(NULL,0));
}
