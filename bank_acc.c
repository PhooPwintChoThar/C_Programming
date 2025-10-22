#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mlock;
int balance=1000;

void* deposit(void* value){

    int amount= *(int*)value;
    pthread_mutex_lock(&mlock);
    balance+=amount;
    printf("Your  balance after deposit 500 : %d \n", balance);
    pthread_mutex_unlock(&mlock);

    return NULL;

}

void* withdraw(void* value){
        int amount= *(int*)value;
        pthread_mutex_lock(&mlock);
        balance-=amount;
         printf("Your  balance after withdraw 300 : %d \n", balance);
        pthread_mutex_unlock(&mlock);

        return NULL;
}

int main(){

    pthread_t threads[10];

    int damount=500;
    int wamount=300;

    pthread_mutex_init(&mlock, NULL );



    pthread_create(&threads[0], NULL, deposit, &damount );
    pthread_create(&threads[1], NULL, deposit, &damount );
    pthread_create(&threads[2], NULL, deposit, &damount );
    pthread_create(&threads[3], NULL, deposit, &damount );
    pthread_create(&threads[4], NULL, deposit, &damount );

    pthread_create(&threads[5], NULL, withdraw, &wamount );
    pthread_create(&threads[6], NULL, withdraw, &wamount );
    pthread_create(&threads[7], NULL, withdraw, &wamount );
    pthread_create(&threads[8], NULL, withdraw, &wamount );
    pthread_create(&threads[9], NULL, withdraw, &wamount );

    for(int i=0; i<10;i++){
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mlock);
    printf("Your final amount : %d \n", balance);

}

// Without mutex there can be a situation that balance is accessed by both deposit and withdraw function
//for example, initial balance is 0 and without mutex lock, the final balance can be 500 or -300  instead of 200