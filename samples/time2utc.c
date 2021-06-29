#include <stdio.h>
#include <time.h>

int main(void) {
    time_t t;   
    time(&t);


   printf("\nThis program has been writeen at (date and time): %s", ctime(&t));

    
    time_t now = time(NULL);
    
    
    if (now == -1) {
        
        puts("The time() function failed");
    }

    printf("utc time %ld\n", now);

    return 0;
}
