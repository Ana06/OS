#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
        int pid = fork();
        if (pid == 0) printf("Child\n");
        else printf("Parent\n");
        printf("pid %i\n", getpid());
        printf("ppid %i\n", getppid());
        printf("pgid %i\n", getpgid(0));
        printf("sid %i\n", getsid(0));
        printf("Dir %s\n", getcwd(NULL,0));
        if (pid == 0){
                setsid();//creates a session and sets the process group ID
                printf("New session\n");
                printf("pid %i\n", getpid());
                printf("ppid %i\n", getppid());
                printf("pgid %i\n", getpgid(0));
                printf("sid %i\n", getsid(0));
                chdir("/tmp");
                printf("Dir %s\n", getcwd(NULL,0));

        } 
        else {
		int status;
                wait(&status);
                printf("The child finished with %i\n", status);
	}
        return 0;

}
