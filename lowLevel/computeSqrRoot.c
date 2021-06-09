# include <stdio.h>
# include <math.h>
int main(void) {
	printf("enter values for input, threshold, max iterations\n");
	int x;
	double thresh;
	int maxI;
	scanf("%d\n",&x);
	scanf("%f\n",&thresh);
	scanf("%d",&maxI);
	printf("%.3f\n",thresh); 
	double r = 5;
	int iter = 0;
	while((r*r-x)<thresh && iter<maxI){
		r=(r+(x/r))/2;
		iter++;
	}
	double act = sqrt(x);
	double diff = r-act;
	printf("square root of %d\n",x);
	printf("newtons method (threshold %f): %f (%d iterations)\n",thresh,r,iter);
	printf("using library function: %f\n",act);
	printf("differance: %f\n",diff);

}
