#include<stdio.h>


#define TRUE 1
#define FALSE 0

int days_in_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[] = 
	{
		" ",
		" \n\n\nJanuary",
		" \n\n\nFebruary",
		" \n\n\nMarch",
		" \n\n\nApril",
		" \n\n\nMay",
		" \n\n\nJune",
		" \n\n\nJuly",
		" \n\n\nAugust",
		" \n\n\nSeptember",
		" \n\n\nOctober",
		" \n\n\nNovember",
		" \n\n\nDecember"
	};


int inputyear(void){
	int year;
	printf("Please Enter a year : ");
	scanf("%d",&year);
	return year;
}


int determineleapyear(int year){
	if(year%4 == FALSE && year%100 != FALSE || year%400 == FALSE){
		days_in_month[2] = 29;
		return TRUE;
	}else{
		days_in_month[2] = 28;
		return FALSE;
	}
}


int determinedaycode(int year){
	int daycode;
	int d1,d2,d3;
	d1=(year - 1.)/4.0;
	d2=(year - 1.)/100;
	d3=(year - 1.)/400;
	daycode=(year + d1 - d2 + d3)%7;
	return daycode;
}


void calender(int year, int daycode) {
    	int month, day;
    	for (month = 1; month <= 12; month++) {
        	printf("%s", months[month]);
       	printf("\n\nSun Mon Tue Wed Thu Fri Sat\n");

        	// Correct the position for the first date
        	for (day = 0; day < daycode; day++) {					
            		printf("    ");
        	}

        	// Print all the dates for one month
        	for (day = 1; day <= days_in_month[month]; day++) {
            		printf("%3d ", day);

            		// Is day before Sat? Else start next line Sun.
            		if ((day + daycode) % 7 == 0) {
                		printf("\n");
            		}
        	}

        	// Set position for next month
        	daycode = (daycode + days_in_month[month]) % 7;
        	printf("\n");
    	}
}


int main(void){
	int year,daycode,leapyear;
	year=inputyear();
	daycode=determinedaycode(year);
	determineleapyear(year);
	calender(year,daycode);
	printf("\n");
	return 0;
}
