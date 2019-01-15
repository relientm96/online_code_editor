/*Add Two Numbers using a seperate function!*/

#include <stdio.h>

//Function that adds two numbers
int addTwoNumbers(int number1, int number2){
    int result = number1 + number2;
    return result;
}

int main(){
    //Create an integer variable 
    int resultFromFunction = addTwoNumbers(100000,300000000);
    //Print out the result
    printf("The result is: %d\n",resultFromFunction);
}