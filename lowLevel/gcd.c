# include <stdio.h>

int main(void){
	int a;
	int b;
	printf("enter two non-negative integers\n");
	scanf("%d %d",&a,&b);
	if(a<0) printf("a was a negative number\n");
	else if(b<0) printf("b was a negative number\n");
	else if(a==0 && b==0) printf("both a and b were zero\n");
	else {
		int gcd(int a, int b){
			if(b==0) return a;
			else gcd(b,a%b);
		}
		printf("the gcd is %d\n",gcd(a,b));
	}
return 0;
}
