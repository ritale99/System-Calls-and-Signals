#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

// Place any necessary global variables here
int loopCount = 0;
struct timeval tv_start;
struct timeval tv_end;
double final_time = 0;
double avg_time = 0;


void handle_sigfpe(int signum){
	// Handler code goes here
	
	if (loopCount == 100000){
		
		gettimeofday(&tv_end, NULL);
		final_time = (tv_end.tv_sec * 1e6 + tv_end.tv_usec) - (tv_start.tv_sec * 1e6 + tv_start.tv_usec);
		avg_time = final_time / loopCount;
		printf("Exceptions Occurred: %d\n", loopCount);
		printf("Total Elapsed Time: %f microseconds\n", final_time);
		printf("Average Time Per Exception: %f microseconds\n", avg_time);

	
		exit(0);
	}
	
	loopCount++; 
	return;
}

int main(int argc, char *argv[]){
	
	int x = 5;
	int y = 0;
	int z = 0;
	signal(SIGFPE, handle_sigfpe); // Register signal handler

	gettimeofday(&tv_start, NULL);

	z = x / y; // This causes the exception
	printf("%d",z);

	return 0;

}
