#include <string.h> //strlen
#include <stdio.h> //printf
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char** argv){
	char *path=argv[1];
	printf("%s\n",path);
	DIR* dir = opendir(path); // pointer to the directory
	if(dir == NULL) return -1;
	int size =0;
	chdir(argv[1]);
	struct dirent* myreaddir = readdir(dir);
	while(myreaddir!= NULL){
		printf("%s",myreaddir->d_name);
		struct stat info;
		lstat(myreaddir->d_name, &info);//lstat, not stat
		if (S_ISDIR(info.st_mode)) printf("/");
		else if (S_ISLNK(info.st_mode)) {
			printf("->");
			char link[pathconf(path, _PC_PATH_MAX)+1];
			ssize_t len = readlink(myreaddir->d_name , link, sizeof(link));
			link[len]='\0';
			printf("%s", link);
		}
		else if (S_ISREG(info.st_mode)){
			if (info.st_mode & S_IXUSR) printf("*");
			size = size + info.st_size;
		}
		printf("\n");
		myreaddir = readdir(dir);
	}
	printf("Size of the files %i Bytes\n",size);

}
