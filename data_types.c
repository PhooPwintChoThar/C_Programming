#include <stdio.h>

int main(){
    int a=23;
    short b=12;
    long c=324324324;


    float p=0.257;
    double q=2342.344332242;

    char m='A';
    char n[10]="string";

    printf("a= %d b=%hd c=%ld p= %f q=%f m=%c, n=%s \n",a,b,c,p,q,m,n);
    printf("p with 2 floating number %.2f: \n", p);
    printf("q with scientific notation %e \n", q);
    return 0;
}