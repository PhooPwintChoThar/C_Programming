#include <stdio.h>
#include <string.h>
int main(){

    int forty=40;
    float fortyFloat=forty*1.0;
    printf("Value %f \n", fortyFloat);

    int converttoInt=(int)3.99;
    int sum = converttoInt+4.1;//will be 8.09 if not coverted to int
    printf("Value %d \n", converttoInt);

    char floatS[30];
    sprintf(floatS, "%f", fortyFloat);
    strcat(floatS,"Hello ");
    char e[40]="Hi ";
    strcat(e, floatS  );
    printf("%s \n", e);


    return 0;
}