#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int notDone = 1; int cnt = 0;
void mySIGhandler(int sig){
	signal(SIGALRM,SIG_IGN);
	notDone = 0;
}
int main(void){
	signal(SIGALRM,mySIGhandler);
	pid_t pid = fork();
	if(pid == 0){
		printf("child create");
		while(1);
		printf("This line should not be show");
		exit(0);
	} else {
		sleep(0);
		kill(pid, SIGINT);
	}
	printf("Papa! Mama kill me!\n");
	return 0;
}
