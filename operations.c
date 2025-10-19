#include <stdio.h>

int main(){
    printf("Operations : \n");
    printf("'Add' 3 + 4 : %d\n", 3+4);
    printf("'Subtract' 3 - 4: %d\n", 3-4);
    printf("'Integer Division use %%d 3 /4 : %d\n", 3/4);
    printf("'Float Division use %%f and (float) 3 /4 : %f\n", (float)3/4);
    printf("'Remainder' 3%%4 : %d\n", 3%4);
    printf("'greater/less than' 3>4  and 3<4 and 3==4 : %d and %d and %d\n", 3>4, 3<4,3==4);
    printf("'greater/less than or equal' 3>=4  and 3<=4 : %d and %d \n", 3>=4, 3<=4);
    int a=3;
    printf("increment of %d pre : %d  post : %d \n",a, ++a, a++);
    printf("decrement of %d pre : %d post : %d \n", a, --a, a--);
    return 0;

}