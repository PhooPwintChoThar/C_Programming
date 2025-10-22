#include <stdio.h>
#include <stdlib.h>
int main(){

    int  *StoreFiveNumsMem =(int*)malloc(5*sizeof(int));

    if(StoreFiveNumsMem == NULL){
        printf("Failed to allocate memory!\n");
        return 0;
    }

    printf("In Memory Allocator: \n");
    for(int i=0; i<5;i++){
        printf("%d -> %d \n", i, StoreFiveNumsMem[i]);

    }

    int  *StoreFiveNumsConMem =(int*)calloc(5 , sizeof(int));

    if(StoreFiveNumsConMem == NULL){
        printf("Failed to continuous allocate memory!\n");
        return 0;
    }

    printf("In Continuous Memory Allocator: \n");
    for(int i=0; i<5;i++){
        printf("%d -> %d \n", i, StoreFiveNumsConMem[i]);

    }

    free(StoreFiveNumsMem);
    //StoreFiveNumsMem = NULL;
    free(StoreFiveNumsConMem);
    //printf("%d -> %d \n", 1, StoreFiveNumsMem[1]);

    return 0;

}