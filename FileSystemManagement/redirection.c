#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char** argv){
	char *path=argv[1];
	printf("This message should appear on the screen%s\n", path);
	int out = open(path, O_CREAT|O_RDWR, 0666);
	close(1);
	fcntl(out, F_DUPFD,1);//dup2(out,1); Coje el 1 o uno mayor si ese no está libre!!
	close(2);
	fcntl(out, F_DUPFD,2);//dup2(out,2);
	printf("This message should not appear on the screen\n");
	fprintf(stderr,"This error should not appear on the screen\n");
	close(out);
}
