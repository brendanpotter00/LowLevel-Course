#include <stdio.h>
#include <string.h>
#include <ctype.h>
//PLEDGE: brendan potter
//this work is entirely my own
int strlen_array(char s[]) {
	int count = 0;
	while (s[count] != '\0') ++count;
	return count;
}

int main(void) {
	char line[40];
	printf("enter a line of text\n");
	fgets(line, sizeof line, stdin);
	char *eol = strchr(line, '\n');
	if (eol == NULL) {
		printf("line too long, maximum length %d\n", (int) sizeof line - 1);
		printf("partial line '%s'\n", line);
		return 1;
	}
	*eol = '\0';
	printf("input '%s'\n", line);
	
	int length = strlen_array(line);
	printf("length test: %d\n",length);
	char *newLine[length];
	int cnt = 0;
	for(int i=0; i<length; ++i){
		if(isdigit(line[i]) || isalpha(line[i])){
			newLine[cnt]=&line[i];
			++cnt;
		}
	}
	
	int isPalen=0;
	int mid = cnt/2;
	for(int i=0; i<cnt; ++i){
		if(*newLine[i]!=*newLine[cnt-i-1]) isPalen = 1;
	}
	if(isPalen==0) printf("a palindrome\n");
	else printf("not a palindrome\n");
}
