/* TASK 1
You would like to store student data (for each student, their name and age) in a linked list of students. You are given the following structure to store each student's information. Please do not modify this structure:

struct student {
      char name[50];
      int age;
      struct student *next;
};
Your first task is to write a function createStudent() that takes as inputs a string (namely a student's name) and an integer (their age) and that returns a pointer to a struct student which stores this information. Your function should dynamically allocate the memory required for this struct student and then write the student's name and age into this newly allocated memory. */

/*
*This task offers 1 hint :
*Hint 1 : It may be useful to create a function copyStr() which copies one string to another string.
*/

#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);

// Write other function prototypes here (if any)
void copyStr(char* source, char* target);


int main(void) {
    struct student *studptr;
    int myAge;
    char myName[50];
    scanf("%s %d", myName, &myAge);
    studptr = createStudent(myName, myAge);
    printf("New student created: %s is %d years old.\n", studptr->name, studptr->age);
    free(studptr);
    return 0;
}

// Write your createStudent function here (and any other functions you see fit)
void copyStr(char* source, char* target) {
    int i = 0;
    while (source[i] != '\0') {
        target[i] = source[i];
        i++;}
    target[i] = '\0';}
struct student *createStudent(char studentName[], int studentAge){
struct student * ptr;
ptr = (struct student*) malloc(sizeof(struct student));
//ptr->name = studentName; it doesn't work((
copyStr(studentName,ptr->name);
ptr->age = studentAge;
ptr->next = NULL;
return ptr;
};

/*TASK 2

In this task you will continue working on the linked list of students in which you would like to store, for each student, their name and age. As before you are provided with some code that you should not modify:

A structure definition for the storage of each student's information.
A main() function to test your code. 
Prototypes for the functions createStudent() (from the previous task) and append() (from the current task).
You will need the function definition (from the previous task) for createStudent(), as well as any other functions you added, such as copyStr() for example. If you were unable to solve the previous task you have the option to be given the code for the createStudent() function (see the quiz preceding this task) so that you can work on the current task.

Your new task is to write a function append() which takes as input two pointers: the first pointer holds the address of the current end of the linked list of students, the second pointer points to a newly created student. Your function should append this new student to the linked list and return the address (a struct student *) of the new end of the list. */

#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student *append(struct student * end, struct student * newStudptr); 
/* add other prototypes here if needed */
void copyStr(char* source, char* target);

int main(void) {
    struct student *start, *newStudptr, *end, *tmp;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);
    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printf("%s is %d years old.\n", start->name, start->age);
    printf("%s is %d years old.\n", start->next->name, start->next->age);
    printf("%s is %d years old.\n", start->next->next->name, start->next->next->age);

    tmp = start->next;
    free(start);
    start = tmp;
    tmp = start->next;
    free(start);
    free(tmp);

    return 0;
}

/* Place your function definitions here. Be sure to include the definition for 
   createStudent() and any other functions you created for the previous task. */
   void copyStr(char* source, char* target) {
    int i = 0;
    while (source[i] != '\0') {
        target[i] = source[i];
        i++;}
    target[i] = '\0';}
    
   
struct student *createStudent(char studentName[], int studentAge){
struct student * ptr;
ptr = (struct student*) malloc(sizeof(struct student));
copyStr(studentName,ptr->name);
ptr->age = studentAge;
ptr->next = NULL;
return ptr;
};

struct student *append(struct student * end, struct student * newStudptr){
end->next = newStudptr;
end = newStudptr;
return (end);
}

/* TASK 3
In this task you will continue working on the linked list of students in which you would like to store, for each student, their name and age. As before you are provided with some code that you should not modify:

A structure definition for the storage of each student's information.
A main() function to test your code. 
Prototypes for the functions createStudent(), append() (from previous tasks) and printStudents() (from the current task).
You will need the function definitions (from previous tasks) for createStudent(), append() as well as any other functions you added, such as copyStr() for example. If you were unable to solve the previous task you have the option to be given the code for the append() function (see the quiz preceding this task) so that you can work on the current task.

Your new task is to write a function printStudents() which takes as input a pointer that holds the address of the start of a linked list of students. Your function should then print this list of students to the screen as specified in the example below. Your function should not return anything.*/

#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[50], int studentAge);
struct student * append(struct student * end, struct student * newStudptr); 
void printStudents(struct student *start);
void copyStr(char* source, char* target);
/* add other prototypes here if needed*/

int main(void) {
    struct student *start, *newStudptr, *end, *tmp;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;

    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);

    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    tmp = start->next;

    free(start);

    start = tmp;
    tmp = start->next;

    free(start);
    free(tmp);

    return 0;
}

/* Place your function definitions here. Be sure to include the definitions for 
   createStudent() and append() as well as any other functions you created for 
   the previous tasks. */
void copyStr(char* source, char* target) {
    int i = 0;
    while (source[i] != '\0') {
        target[i] = source[i];
        i++;}
    target[i] = '\0';}
    
   
struct student *createStudent(char studentName[], int studentAge){
struct student * ptr;
ptr = (struct student*) malloc(sizeof(struct student));
copyStr(studentName,ptr->name);
ptr->age = studentAge;
ptr->next = NULL;
return ptr;
};

struct student *append(struct student * end, struct student * newStudptr){
end->next = newStudptr;
end = newStudptr;
return (end);
} 

void printStudents(struct student *start){
 
    struct student * pntr = start;
    while (pntr!=NULL) {
        printf("%s is %d years old.\n", pntr->name, pntr->age);
        pntr = pntr->next;
    }
    
}

/*TASK 4
In this task you will continue working on the linked list of students in which you would like to store, for each student, their name and age. As before you are provided with some code that you should not modify:

A structure definition for the storage of each student's information.
A main() function to test your code. 
Prototypes for the functions createStudent(), append(), printStudents (from previous tasks) and freeStudents() (from the current task).
You will need the function definitions (from previous tasks) for createStudent(), append(), printStudents() as well as any other functions you added, such as copyStr() for example. If you were unable to solve the previous task you have the option to be given the code for the printStudents() function (see the quiz preceding this task) so that you can work on the current task.

Your current task is to write a function freeStudents() which takes as input a pointer that holds the address of the start of a linked list of students. Your function should then free the space allocated for each student in this list of students. Your function should not return anything.
*/

#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student *append(struct student * end, struct student * newStudptr);
void printStudents(struct student *start);
void freeStudents(struct student *start);
/* add any other prototypes as needed */
void copyStr(char* source, char* target);

int main(void) {
    struct student *start, *newStudptr, *end;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    freeStudents(start);

    return 0;
}

/* Place your function definitions here. Be sure to include the definitions for 
   createStudent(), append(), printStudents() as well as any other functions you 
   created for the previous tasks. */
void copyStr(char* source, char* target) {
int i = 0;
while (source[i] != '\0') {
target[i] = source[i];
i++;}
target[i] = '\0';}
    
   
struct student *createStudent(char studentName[], int studentAge){
struct student * ptr;
ptr = (struct student*) malloc(sizeof(struct student));
copyStr(studentName,ptr->name);
ptr->age = studentAge;
ptr->next = NULL;
return ptr;
};


struct student *append(struct student * end, struct student * newStudptr){
end->next = newStudptr;
end = newStudptr;
return (end);
} 


void printStudents(struct student *start){
struct student * pntr = start;
while (pntr!=NULL) {
printf("%s is %d years old.\n", pntr->name, pntr->age);
pntr = pntr->next;}    
}


void freeStudents(struct student *start){
struct student * ptr = start;
struct student * tmp;
while (ptr!=NULL) {
tmp = ptr->next;
free(ptr);
ptr = tmp;}
}


/*TASK 5
In this task you will work with the linked list of digits we have created in the lessons up to this point. As before you are provided with some code that you should not modify:

A structure definition for the storage of each digit's information.
A main() function to test your code. 
The functions createDigit(), append(), printNumber(), freeNumber() and readNumber() which we have written in the lectures.
Your task is to write a new function divisibleByThree() which takes as input a pointer that holds the address of the start of a linked list of digits. Your function should then check whether the number stored in this linked list of digits is divisible by three. The function should return the value 1 if indeed the number is divisible by three and it should return the value 0 otherwise.*/

#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

// Write your prototypes here
struct digit *createDigit(int dig);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *start);
void freeNumber(struct digit *start);
struct digit *readNumber(void);
int divisibleByThree (struct digit * div3);

int main(void) {
    struct digit *start;
    start = readNumber();
    printf("The number ");
    printNumber(start);
    if (divisibleByThree(start)) 
        printf("is divisible by 3.\n");
    else
        printf("is not divisible by 3.\n");
    freeNumber(start);
    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit *readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

// Write your divisibleByThree() function here
int divisibleByThree (struct digit * div3){
int div;
int sum = 0;
struct digit *ptr = div3;
while (ptr!= NULL){
sum+=ptr->num;
ptr = ptr->next;}
if (sum %3==0){
div = 1;}
else {div = 0;}
return div;}


/*TASK 6

In this task you will work with the linked list of digits we have created in the lessons up to this point. As before you are provided with some code that you should not modify:

A structure definition for the storage of each digit's information.
A main() function to test your code. 
The functions createDigit(), append(), printNumber(), freeNumber(), readNumber() and divisibleByThree() (although you may not need to use all of these).

Your task is to write a new function changeThrees() which takes as input a pointer that holds the address of the start of a linked list of digits. Your function should change all of those digits in this linked list that equal 3 to the digit 9, and count how many replacements were made. The function should return this number of replacements.

*/
#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

struct digit * createDigit(int dig);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *start);
void freeNumber(struct digit *start);
int divisibleByThree(struct digit * start);
struct digit * readNumber(void);
//Add your own function prototypes here
int changeThrees(struct digit * start)

int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("was modified in %d places.\n", changeThrees(start));

    printf("The new number is ");
    printNumber(start);
    freeNumber(start);

    return 0;
}

struct digit * createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit * readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

int divisibleByThree(struct digit * start) {
    struct digit * ptr = start;
    int qsum = 0;
    while (ptr!=NULL) {
        qsum += ptr->num;
        ptr = ptr->next;
    }
    if (qsum%3==0) return 1;
    else return 0;
}

// Write your changeThrees() function here
int changeThrees(struct digit * start){
int count =0;
struct digit * ptr = start;
while (ptr!= NULL){
     if (ptr->num == 3){
     ptr->num = 9;
     count++;}
ptr = ptr->next;}

return count;}

/*
TASK 7
In this task you will again work with the linked list of digits we created during the lessons up to this point. 

You are provided with (but are not required to use) the functions and prototypes we have written so far. You are also provided with a main() function to test your code. Please do not modify this main() function.

Your task is to write a new function countRedun() which takes as input a pointer that holds the address of the start of a linked list of digits. Your function should count how many redundancies can be observed in the number stored in this list and return this count of redundancies. A redundancy is a digit which has previously already occurred in the number. For example, in the number 39534, the second '3' is a redundancy.
*/ 

#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};


// Add a prototype for countRedun() here

int countRedun(struct digit * start);
struct digit * sortedCopy(struct digit * start);
struct digit * insertAtFront(struct digit * start, struct digit * newptr);
struct digit * insertIntoSorted(struct digit *start, struct digit *newDig);

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit *readNumber(void); 
 


// Do not modify this main() function
int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));

    freeNumber(start);

    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit *readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}


/*I have used the sortedCopy(), insertAtFront() and insertIntoSorted() from the lecture
to sort the linked list*/
struct digit * insertIntoSorted(struct digit *start, struct digit *newDig) {
    struct digit *ptr = start;
    struct digit *prev = NULL;
    while ((ptr!=NULL) && (ptr->num < newDig->num)) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev == NULL) {
        start = insertAtFront(start, newDig);
    } else {
        prev->next = newDig;
        newDig->next = ptr;
    }
    return(start);
}


struct digit * insertAtFront(struct digit * start, struct digit * newptr) {
    newptr->next = start;
    return(newptr);
}


struct digit * sortedCopy(struct digit * start) {
     
    struct digit *ptr = start;
    struct digit *sortedStart = NULL;
    struct digit *newDigit;
    
    if (start!=NULL) {
        sortedStart = createDigit(start->num);
        ptr = ptr->next;
    }
    while (ptr!=NULL) {
        newDigit = createDigit(ptr->num);
        sortedStart = insertIntoSorted(sortedStart, newDigit);
        ptr = ptr->next;
    }
    return(sortedStart);
}

// Write your countRedun() function here
int countRedun(struct digit * start){
//I will create a temporary copy of start
struct digit * ptr = start;

//I will sort this new linked list
ptr = sortedCopy(ptr);

 
//I will count redundancies
int count=0;
while (ptr!=NULL){

    if (ptr->next!=NULL && ptr->num == ptr->next->num){            
    count++;
    }
 
ptr = ptr->next;
 
 }
 

return count;
}

