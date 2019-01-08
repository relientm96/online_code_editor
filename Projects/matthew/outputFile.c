/*Press Compile to see the result!*/

#include <stdio.h>
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