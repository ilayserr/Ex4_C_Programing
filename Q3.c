#include <stdio.h>

/***************************************
This is a C program for sorting 3 numbers using pointers

Name : Ilay Serr
Email : ilay92@gmail.com
************************/

/*** Function declarations ***/

// The function swap between two given "by reference" numbers
void swap(int*, int*);

// The function recieves 3 pointers to numbers and arrange them by 
// size a < b < c using the swap function.
void order_nums(int*, int*, int*);

// recieves 3 numbers from the user and insert them instead of the
// pointers given.
int fill_nums (int*, int*, int*);

/*** main ***/
int main() {
   int a ,b ,c, legal;
   printf("Please enter 3 numbers: ");
   legal = fill_nums(&a, &b, &c);
   if (legal == 0) {
      printf("Invalid input!\n");
      return 1;
   }
   order_nums(&a, &b, &c);
   printf("%d, %d, %d\n", a, b, c);
   return 0;
}
/*** end of main() ***/

/************************************
Function swap
Params:
- newA - a pointer (of type int*) to a variable
- newB - a pointer (of type int*) to a variable 
A function that swap between two numbers while it has only the numbers pointers
no return - void function
***********************************/
void swap(int* newA, int* newB) {
   int temp = *newA;
   *newA = *newB;
   *newB = temp;
}

/************************************
Function order_nums
Params:
- newA - (type int*) a pointer to a variable (in our case - variable a in main)
- newB - (type int*) a pointer to a variable (in our case - variable b in main)
- newC - (type int*) a pointer to a variable (in our case - variable c in main)
A function that sort three numbers while it has only the numbers 
pointers, the function uses the swap function
no return - void function
***********************************/
void order_nums(int* newA, int* newB, int* newC) {
   if (*newA > *newB) swap(newA, newB);
   if (*newA > *newC) swap(newA, newC);
   if (*newB > *newC) swap(newB, newC);
}

/************************************
Function fill_nums
Params:
- newA - (type int*) a pointer to a variable (in our case - variable a in main)
- newB - (type int*) a pointer to a variable (in our case - variable b in main)
- newC - (type int*) a pointer to a variable (in our case - variable c in main)
- input - the number of valid variables entered by the user
A function that get three numbers from the user, enters them into the pointers
given.
return: the number of valid variables receiven.
***********************************/
  
int fill_nums (int* newA, int* newB, int* newC) {
   
   int input = scanf("%d %d %d", newA , newB, newC);
   if (input == 3) return 1;
   else return 0;
}


