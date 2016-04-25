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
	printf("Tipo de archivo: ");
	if (S_ISLNK(buf.st_mode))
		printf("enlace simbólico\n");
	else if(S_ISREG(buf.st_mode))
		printf("fichero regular\n");
	else if(S_ISDIR(buf.st_mode))
		printf("directorio\n");
	printf("Accedido por última vez: %s\n", ctime(&(buf.st_mtime)));
	//st_mtime:modificado por llamadas write, mknod, utime. No en cambio de usuario,grupo,permisos. st_ctime: modificado si se altera la información del inodo.
}
