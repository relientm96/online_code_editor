/*Add Two Numbers using a seperate function!*/

#include <stdio.h>

//Function that adds two numbers
double addTwoNumbers(double number1, double number2){
    double result = number1 + number2;
    return result;
}

int main(){
    //Create an integer variable 
    double resultFromFunction = addTwoNumbers(2.4,3.55555);
    //Print out the result
    printf("The result is: %3.2f\n",resultFromFunction);
}