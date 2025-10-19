#include <stdio.h>
#include <string.h>

int main(){
    char str[15]="Hello World";

    printf("size of Hello World : %zu\n", strlen(str));

    char names[4][10]={"Mary", "Alice", "Jerry", "Taylor"};

    printf("size of names array : %zu\n", sizeof(names)/sizeof(names[0]));
    
    
}