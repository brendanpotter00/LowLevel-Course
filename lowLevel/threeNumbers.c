# include <stdio.h>
# include <string.h>

int main(void){
	int num1;
	int num2;
	int num3;
	printf("enter three numbers\n");
	scanf("%d %d %d",&num1,&num2,&num3);
	printf("the numbers were %d %d %d\n",num1,num2,num3);
	int sml;
	int med;
	int lrg;
	if (num3>=num1){
		if (num1>=num2){
			sml=num2;
			med=num1;
			lrg=num3;
		} 
		else if(num3>=num2){
			sml=num1;
			med=num2;
			lrg=num3;
		}
	}
	else if(num1<=num2){
		sml=num3;
		med=num1;
		lrg=num2;
	}
	else{
		sml=num3;
		med=num2;
		lrg=num1;
	}
	printf("from smallest to largest %d %d %d\n",sml,med,lrg);
return 0;
}
