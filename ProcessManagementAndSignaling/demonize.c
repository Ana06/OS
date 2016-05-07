#include <unistd.h>
#include <stdio.h>
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

int main(int argc, char** argv){
        int pid = fork();
        if (pid == 0){
                setsid();//creates a session and sets the process group ID	
                chdir("/tmp");
                int o = open("daemon.out", O_CREAT|O_WRONLY|O_TRUNC);
                dup2(o,1);
                int e = open("daemon.err", O_CREAT|O_WRONLY|O_TRUNC);
                dup2(e,2);
                int i = open("/dev/null", O_RDONLY);
                dup2(i,0);
        	execlp("/bin/sh","/bin/sh","-c",argv[1],NULL);
		printf("The execution has finished\n");
	}
}
