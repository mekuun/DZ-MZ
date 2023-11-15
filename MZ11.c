#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(){
	int N;
	scanf("%d", &N);
	int pid = getpid();


	while (N >= 0){
		N--;
		if (fork()){
			if (pid != getpid()){
				fprintf(stdout, "%d %d \n", getpid()-getppid(), getpid() - pid);
				fflush(stdout);
				fprintf(stderr, "PID = %d PPID = %d\n", getpid(), getpid());
				fflush(stderr);
				wait(NULL);
				return 0;
			}
			wait(NULL);
			return 0;
		}
	}
return 0;
}

	

			



