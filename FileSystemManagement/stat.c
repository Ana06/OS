#define _BSD_SOURCE //major minor
#include <sys/types.h> //stat
#include <sys/stat.h> //stat
#include <unistd.h> //stat
#include <stdio.h> //printf
#include <sys/types.h> //major minor



int main(int argc, char** argv){
	struct stat buf;
	int i = stat(argv[1], &buf);
	if(i == -1){
		perror("stat");
		return -1;
	}
	printf("Major: %i\n", major(buf.st_dev));
	printf("Minor: %i\n", minor(buf.st_dev));
	printf("I-nodo: %i\n", buf.st_ino);
	printf("file type: ");
	if (S_ISLNK(buf.st_mode))
		printf("symbolic link\n");
	else if(S_ISREG(buf.st_mode))
		printf("regular file\n");
	else if(S_ISDIR(buf.st_mode))
		printf("directory\n");
	printf("Last time accessed: %s\n", ctime(&(buf.st_mtime)));
	//st_mtime: when it is modified by write, mknod or utime calls, not when changing user, group or ppermission. 
	//st_ctime: when the i-node information is modified.
}
