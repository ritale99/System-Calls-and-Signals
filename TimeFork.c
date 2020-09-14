#include <stdlib.h>
#include <stdio.h>


#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[]){ 
	struct timeval tv_start;
	struct timeval tv_end;
	int i = 0;
	int loopCount = 5000;
	double final_time = 0;
	double avg_time = 0;
	gettimeofday(&tv_start, NULL);

	for (i = 0 ; i < loopCount ; i++ ){
		if ( fork() == 0 )//child
			exit(0);
		else			  //parent
			wait(NULL);
	}
	

	gettimeofday(&tv_end, NULL);
	final_time = (tv_end.tv_sec * 1e6 + tv_end.tv_usec) - (tv_start.tv_sec * 1e6 + tv_start.tv_usec);
	avg_time = final_time / loopCount;
	printf("Forks Performed: %d\n", loopCount);
	printf("Total Elapsed Time: %f microseconds\n", final_time);
	printf("Average Time Per Fork: %f microseconds\n", avg_time);
	return 0;

}
