/*Press compile to see what the time is on the server!*/
//This uses the time library

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
  
int main(){

    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);
	
    printf("   Date      Time\n");
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(buffer);

    return 0;
  
}