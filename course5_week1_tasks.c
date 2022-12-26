/*TASK 1

You'd like to implement a date feature in the C programming language. To this end you are provided with a structure definition, a main function, and two function prototypes: "readDate()" and "printDate()". All that is left for you to do is to write these two functions.

Here are the exact specifications:

The function readDate() should read 3 integers from the user input. The first integer is the year (a 4-digit number), the second integer is the month, and the third integer is the day of the date being read. The function should store these three numbers in the appropriate parts of the structure being passed into it.

The function printDate() should print the date stored in the variable passed into it in the following format: mm/dd/yyyy with a new line afterwards. So the month should be printed with two digits (01, 02, 03, ..., 11, 12), the day should be printed as two digits (01, 02, 03, ..., 30, 31), and the year should be printed as a 4-digit number.

You should not modify the provided code.*/

#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void readDate(struct date *);
void printDate(struct date);

int main(void) {
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}
void readDate(struct date* dd){
scanf("%d %d %d", &(*dd).year,&(*dd).month,&(*dd).day);
}
void printDate(struct date dd){
printf("%02d/%02d/%4d\n", dd.month, dd.day, dd.year);

	
/*TASK 2

In this problem you will continue developing the data feature which you started implementing in the previous problem. You will implement a "tomorrow" feature in the C programming language via a function called "advanceDay()". The function advanceDay() should take as input a date (stored in a struct date) and return the date of the following day. You do not have to take into account leap years (although you may if you wish to). That is, it is okay for your function to always return March 1 as the day following February 28, no matter the year.

You are provided with a familiar date structure definition, a main function as well as the function prototypes for the readDate(), printDate(), and advanceDate() functions. Do not modify any of the given code. Simply add your function definitions underneath the main() function. For the readDate() and printDate() functions you may simply copy and paste the code you developed in the previous task.*/

#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

/* function prototypes */
struct date advanceDay(struct date);
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date); 

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

/* add your function definitions here */
struct date advanceDay(struct date nx){
nx.day = (nx.day)+1;
   if((nx.day ==31 && (nx.month==4 || nx.month == 6 || nx.month == 9 || nx.month == 11)) || (nx.day == 32)) {
       nx.day = 1;
       nx.month = (nx.month)+1;}         
   
   if (nx.month == 13){    
       nx.year = (nx.year)+1;
       nx.month =1;}
return nx;
}
