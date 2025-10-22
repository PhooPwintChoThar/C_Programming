#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mlock;

void* print_num(void* arg){
    pthread_mutex_lock(&mlock);
    for(int i=1; i<=1000; i++){
        printf("%d ",i);
    }
    printf("\n");
    pthread_mutex_unlock(&mlock);

    return NULL;
}


int main(){
    pthread_t t1, t2;
    pthread_mutex_init(&mlock, NULL);
    pthread_create(&t1, NULL, print_num, NULL);
    pthread_create(&t2, NULL, print_num, NULL);


    pthread_join(t1,NULL );
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mlock);
    printf("Bye Bye Guys!");
    return 0;
}

//comment out mutex lines to see the difference
//comment out pthread_join() to see the difference