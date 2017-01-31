#include <stdio.h>
/***************************************
This is a C program for computing factorial and factorial sum for a number.

Name : Ilay Serr
Email : ilay92@gmail.com
************************/

/*** Function declarations ***/
                               
// Calculating the factorial of a given integer, returns the factorial.
int factorial(int);

// Calculate and returns the following sum for a given: S(n) = 1! + 2!... + n!
// using the factorial function
int factorials_sum(int);

// Calculating the factorial of a given integer, returns the factorial. 
// using a static variable to make it more efficient.
int optimized_factorial(int);

// Calculate and returns the following sum for a given: S(n) = 1! + 2!... + n!
// using the optimized_factorial function
int optimized_factorials_sum(int);

/*** main ***/
int main() {
   int num, input;
   printf("Please enter a positive number: ");
   input = scanf("%d", &num);
   if ((input != 1) || num < 0) {
      printf("Invalid input!\n");   
      return 1;
   }
   
   printf("Factorial for %d: %d\n" ,num ,optimized_factorial(num)); 
   printf("Sum of factorials for %d: %d\n" ,num, optimized_factorials_sum(num));
   
   return 0;  
}

/*** end of main() ***/                                   

/************************************
Function factorial
Params:
- num - the given positive integer 
- multiplier - the number that "run" in the for loop
- result - the result of the program, updated during the program run.
A function that calculate the given number factorial value.
Example for n: n! = 1 * 2 * 3 * .... * n
Return value: num!
***********************************/

int factorial(int num) {
   int multiplier, result;
   if (num < 0) return -1;
   result = 1;
   for (multiplier = 2; multiplier <= num; multiplier++) {
      result *= multiplier;  
   }       
   return result;        
}

/************************************
Function factorial_sum
Params:
- num - the given positive integer 
- i - the number that "run" in the for loop
- result - the result of the program, updated during the program run.
A function that calculate the given number factorial sum value.
Example for n: S(n) = 1! + 2!... + n!
Return value: S(n)
***********************************/

int factorials_sum(int num) {
   int i, result;
   result = 0;
   for (i = 1; i <= num; i++) {
      result += factorial(i);
   }
   return result;
}

/************************************
Function optimized_factorial
params:
- num - the given positive integer 
- multiplier - the number that "run" in the for loop
- result - a local static variable that stat the last result calculated
  updated during the program run.
- it - a local static variable that states what is the last number calculated.
A function that calculate the given number factorial value in an efficient way.
Example for n: n! = 1 * 2 * 3 * .... * n
Return value: num!
***********************************/

int optimized_factorial(int num) {
   int static result = 1, it = 0;
   int multiplier;
   if (num < 0) return -1;
   else if (num == it) return result;
   else if (num > it) {
      for (multiplier = it + 1; multiplier <= num; multiplier++) {
         result *= multiplier;
      }
   } else if (num < it) {
      if (it - num < num) {
         for (multiplier = it; multiplier > num; multiplier--) {
            result /= multiplier;
         }
      } else {
         result = 1;
         for (multiplier = 2; multiplier <= num; multiplier++) {
            result *= multiplier;
         }
      }
   }
   it = num;
   return result;
}

 /************************************
Function factorial_sum
Params:
- num - the given positive integer
- i - the number that "run" in the for loop
- result - the result of the program, updated during the program run.
A function that calculate the given number factorial sum value.
using the optimized_factorial function for efficiency.
Example for n: S(n) = 1! + 2!... + n!
Return value: num!
***********************************/

int optimized_factorials_sum(int num) {
   int i, result;
   result = 0;
   if (num == 0) return 1;
   for (i = 1; i <= num; i++) {
      result += optimized_factorial(i);
   }
   return result;
}
          
