#include <stdio.h>
#include <math.h>
/***************************************
This is a C program for computing if an integer is aa prime number or not

Name : Ilay Serr
Email : ilay92@gmail.com
************************/

/*** function declarations ***/

// checks if a number is a prime number, returns 1 if it is and 0 otherwise
int is_prime(int);

/*** main ***/
int main() {
   int num, result, input, i;
   printf("Please enter an integer greater than 1: ");
   input = scanf("%d", &num);
   if ((input != 1) || num <= 1) {
      printf("Invalid input!\n");
      return 1;
   }
   for (i = 2; i <= num; i++) {
       result = is_prime(i);
       if (result == 1) {
          printf("%d is a prime number\n" , i);
       }
   } 
   return 0;
}
/*** end of main() ***/

/************************************
function is_power
params:
- num - the integer given to check if prime or not.
- root - the square root of the integer given.
- divider - the variable to run in the for loop, runs from 2 until root           
the function checks for every number (from 2 until the root of the given number)
whether is a divider of the number given or not
return value: 1 if the number is prime and 0 otherwise.
***********************************/

int is_prime(int num) {
   double root;
   int divider;
   root = sqrt((double)num);
   for (divider = 2; divider <= root; divider++) {
      if (num % divider == 0) {
         return 0;
      }
   }
   return 1;
}
     
