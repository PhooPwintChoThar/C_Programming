#include <stdio.h>
#include <string.h>

struct Book{

    char title[30];
    char author[30];
    float price;


};

int main(){

    struct  Book b1;
    strcpy(b1.title, "What do u eat daily?");
    strcpy(b1.author, "Someone");
    b1.price=40.35;

    printf("Title: %s\n", b1.title);
    printf("Author: %s\n", b1.author);
    printf("Price: %f\n", b1.price);

    return 0;
    

}