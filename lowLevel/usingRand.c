#include <stdio.h>
#include <stdlib.h> /* has rand(), srand(), RAND_MAX */

int main(void) {

	int seed;
	int samples;
	int bins;
	printf("seed?\n");
	if (scanf("%d", &seed) != 1) {
		printf("invalid input\n");
		return 1;
	}
	if (seed <= 0) {
		printf("invalid input\n");
		return 1;
	}
	printf("how many samples?\n");
	scanf("%d",&samples);
	printf("how many bins?\n");
	scanf("%d",&bins);

	/* FIXME:  
 * 	 * replace the rest of this code with your code (but okay to keep
 * 	 	 * anything you think will help).
 * 	 	 	 */
	#define ASIZE samples-1
	int set[ASIZE];
	for(int i =0;i<ASIZE;++i){
		set[i]=rand();
	}
	
	
	int counts[bins];
	for(int i=0;i<samples;++i){
		if(set[i]%bins==0) counts[0]++;
		else if(set[i]%bins==1) counts[1]++;
		else if(set[i]%bins==2) counts[2]++;
		else if(set[i]%bins==3) counts[3]++;
		else if(set[i]%bins==4) counts[4]++;
		else if(set[i]%bins==5) counts[5]++;	
	}
	printf("counts using the remander method:\n");
	for(int i=0;i<bins;++i){
		printf("(%d) %f\n"),i,counts[i];
	}
	int counts2[bins];
	for(int i=0;i<samples;++i){
                if(set[i]*bins/(RAND_MAX+1.0)==0) counts[0]++; 
                if(set[i]*bins/(RAND_MAX+1.0)==1) counts[1]++;
		if(set[i]*bins/(RAND_MAX+1.0)==2) counts[2]++;
		if(set[i]*bins/(RAND_MAX+1.0)==3) counts[3]++;
		if(set[i]*bins/(RAND_MAX+1.0)==4) counts[4]++;
		if(set[i]*bins/(RAND_MAX+1.0)==5) counts[5]++;
	}
	printf("counts using quotient method:\n");
	for(int i=0;i<bins;++i){
                printf("(%d) %f\n"),i,counts2[i];
        }

	return 0;
}
