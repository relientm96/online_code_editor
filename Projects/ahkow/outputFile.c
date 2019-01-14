#include <stdio.h>

int main(){
  
   //Print out the result
   int array[5];
  
   for(int i = 0; i < 5 ; i++){
     array[i] = i;
     printf("i = %d\n", array[i]);
   }
  
   return 0;
  
}