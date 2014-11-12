#include <stdio.h>
#include <stdlib.h>

main(){
    char s[256];
    double decimal;

    gets(s);
    decimal = atof(s);
    printf("%s >>> %f >>> %f", s, decimal, decimal*2);
}