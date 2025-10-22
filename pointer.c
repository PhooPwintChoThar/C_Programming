#include <stdio.h>


void passByValue(int n){
    ++n;
    printf("In pass by value, after increment : %d\n", n);
}

void passByRef(int *n){
    ++(*n);
    printf("In pass by reference, after increment : %d\n", *n);
}

void modifyCopy(int arr[], int size) {
    int copy[3];
    for(int i=0;i<size;i++) copy[i]=arr[i];  
    copy[0] = 999;                            
}

void modifyOrigin(int arr[], int size) {
    arr[0]=999;
}


int main(){

    int a=5;
    int *p= &a;
    printf("Address of a : %p\n", p);
    printf("derefrence value of p : %d\n", *p);

    passByValue(a);
    printf("After pass by value fn called, value of a : %d\n", a);
    passByRef(&a);
    printf("After pass by ref fn called, value of a : %d\n", a);

    int nums[3]={1,2,3};
    int *q=nums;//without &
    printf("Address of array: %p \n", q);
    printf("first index of array: %d \n", *q);
    printf("second index of array: %d \n", *(q+1));

    modifyCopy(nums, 3);
    printf("After modifyCopy, first value of nums : %d\n", nums[0]);

    modifyOrigin(nums, 3);
    printf("After modifyOrigin, first value of nums : %d\n", nums[0]);



    return 0;
}