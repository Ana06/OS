#include <sys/types.h> //stat
#include <sys/stat.h> //stat
#include <unistd.h> //stat
#include <stdio.h> //printf
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv){
	char *path=argv[1];
	struct stat buf;
	int i = stat(path, &buf);
	if(i == -1){
		perror("stat");
		return -1;
	}
	if(!S_ISREG(buf.st_mode)){
		printf("It is not a regular file");
		return -1;
	}
	char* newsym = malloc(sizeof(char) * strlen(path) +5);
	strcpy(newsym, path);
	symlink(path, strcat(newsym, ".sym"));
	free(newsym);
	char* newfis = malloc(sizeof(char) * strlen(path) +6);
	strcpy(newfis, path);
	link(path, strcat(newfis, ".hard"));
	free(newfis);
}
