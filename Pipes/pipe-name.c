#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv){
	char* home = getenv("HOME");
	char* path = "/tuberia";
	size_t len = strlen(home) + strlen(path) + 1;
	char* fullpath = malloc(len);
	strcpy(fullpath, home);
	strcat(fullpath, path);

	int fd= open(fullpath, O_WRONLY);
	write(fd, argv[1], strlen(argv[1]));
	close(fd);
}
