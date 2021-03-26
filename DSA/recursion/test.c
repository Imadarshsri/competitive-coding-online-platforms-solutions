#include<stdio.h>
 
void swap (char** x, char** y)
{
    char** t = x;
    x = y;
    y = t;
}
 
int main()
{
    char *x = "geeksquiz"; // Dangerous

    char *y = "geeksforgeeks"; // Dangerous
    
    char *t;
    swap(&x, &y);
    printf("old: (%s, %s)", x, y);
    t = x;
    x = y;
    y = t;
    printf("\nswapped: (%s, %s)", x, y);
    return 0;
}