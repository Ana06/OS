#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

int main(int argc, char** argv){
	char buf[256];
	int tub1 = open("tuberia",O_RDWR|O_NONBLOCK); 
	int tub2 = open("tuberia2",O_RDWR|O_NONBLOCK);
	fd_set s;
	FD_ZERO(&s);
	FD_SET(tub1, &s);
	FD_SET(tub2, &s);
	int max = tub1;
	int r;
	if ( tub2 > tub1 ) max = tub2;
	int val = select(max+1, &s, NULL, NULL, NULL);
	if (val){
		if (FD_ISSET(tub1, &s)){
			printf("tuberia1\n");
			r = read(tub1, buf, 256);
		}else{
			printf("tuberia2\n");
			r = read(tub2, buf, 256);
		}
		buf[r] = '\0';
		printf("%s", buf);
	}
	close(tub1);
	close(tub2);
}
