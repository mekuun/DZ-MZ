#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	
	int N;
	scanf("%d", &N);

	for(int i = 1; i <= N; i ++){
		if (fork() == 0){ /* IF SON */
			fprintf(stdout, "son %d\n", i);
			fflush(stdout);
			fprintf(stderr, "PID = %d PPID = %d\n", getpid(), getppid());
			fflush(stderr);
			return 0;
		}
		else
		wait(NULL);
	}
return 0;
}


		

	



