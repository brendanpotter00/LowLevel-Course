# include <stdio.h>
int main(void) {
	int seconds;
	printf("input number of seconds\n");
	scanf("%d", &seconds);
	int year = seconds/31540000;
	int sec = seconds-year*31540000;
	int day = sec/86400;
	sec = sec-day*86400;
	int hour = sec/3600;
	sec = sec-hour*3600;
	int min = sec/60;
	sec = sec-min*60;
	printf("%d seconds is %d years, %d days, %d hours, %d minute, and %d sec.\n", seconds,year,day,hour,min,sec);

	return 0;
}
