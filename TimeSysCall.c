#include <stdlib.h>
#include <stdio.h>

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

// Place any necessary global variables here

int main(int argc, char *argv[]){
	struct timeval tv_start;
	struct timeval tv_end;
	int i = 0;
	int loopCount = 100000;
	double final_time = 0;
	double avg_time = 0;
	gettimeofday(&tv_start, NULL);
	for ( i = 0 ; i < loopCount ; i++ ){
		getpid();
	}
	gettimeofday(&tv_end, NULL);
	final_time = tv_end.tv_usec - tv_start.tv_usec;
	avg_time = (final_time)/loopCount;
	printf("Syscalls Performed: %d\n", loopCount);
	printf("Total Elapsed Time: %f microseconds\n", final_time);
	printf("Average Time Per Syscall: %f microseconds\n", avg_time);
	return 0;
}
