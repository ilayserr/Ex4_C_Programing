#include <stdio.h>
#include <stdlib.h>

/***************************************
This is a C program for computing the number PI according to the Monte Carlo
method, using num (input from the user) sample points.

Name : Ilay Serr
Email : ilay92@gmail.com
************************/

/*** Function declarations ***/

// recieves a number and calculate PI according to the Monte Carlo method.
// the number given represent the number of points sampled.
double calc_pi(int);

/*** main ***/
int main() {
   int input, num;
   double myPi;
   printf("Please enter the number of points: ");
   input = scanf("%d", &num);
   if ((input != 1) || num <= 0) {
      printf("Invalid input!\n");
      return 1;
   }
   myPi = calc_pi(num);
   printf("The approximated value of PI using %d points is: %f \n", num , myPi);
   return 0;
}
/*** end of main() ***/

/************************************
Function calc_pi
params:
- num - the number of points to sample.
- i - the itterator for the for loop
- count - counts the number of points that in the upper-right circle quarter 
- x - a random number in the range of 0....1
- y - a random number in the range of 0....1
- myPi - the estimate value of Pi.
The function uses the Monte Carlo method to calculate the estimate value of Pi
the level of accurecy of the result will be according to the input number given
return: the estimate value of PI
***********************************/
double calc_pi(int num) {
   int i ,count = 0;
   double x, y, myPi;
   for (i = 0; i < num; i++) {
      x = (double)rand() / RAND_MAX;
      y = (double)rand() / RAND_MAX;
      if ((x*x + y*y) <= 1)
         count++;
   }
   myPi = 4 * ((double)count / num); 
   return myPi;
}


