# include <stdio.h>

int add(int a, int b) {
	return a+b;
}

int factorial(int n){
	if(n <= 1) return 1;
	else return n*factorial(n-1);
}

int main(void) {
	int a = 10;
	double b = 10.2;
	
	printf("a %d\n",a);
	printf("hello world\n");
	
	printf("enter int, double\n");
	scanf("%d %lf", &a, &b);
	printf("a %d, b = %f \n", a,b);
	
	printf("a + b =%d\n",add(a,b));
	printf("a factorial = %d\n",factorial(a));

	return 0;
}
