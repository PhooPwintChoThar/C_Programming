#include<stdio.h>
#include<pthread.h>
#include<stdbool.h>

typedef int64_t cents_t;

cents_t balance =100000;
pthread_mutex_t mlock=PTHREAD_MUTEX_INITIALIZER;

void * deposit(void* amount){
    cents_t am=*(cents_t*)amount;
    cents_t snap;
    pthread_mutex_lock(&mlock);
    balance += am;
    snap=balance;
    pthread_mutex_unlock(&mlock);
    printf("Deposited : %.2f . Current balance : %.2f .\n", am/100.0, snap/100.0);
    return NULL;
}

void * withdraw(void* amount){
    cents_t am=*(cents_t*)amount;
    cents_t snap;
    bool  withdrawed=false;
    pthread_mutex_lock(&mlock);
    if(balance>=am){
        balance -=am;
        withdrawed=true;
    }
    snap =balance;
    pthread_mutex_unlock(&mlock);
    if(withdrawed)
    printf("Withdrawed : %.2f . Current balance : %.2f .\n", am/100.0, snap/100.0);
    else
    printf("Withdraw failed. Current balance : %.2f.\n", snap/100.0);
    return NULL;
}

int main(){
    pthread_t t1, t2;
    cents_t d_amount= 50000;
    cents_t w_amount=20000;

    pthread_create(&t1, NULL, deposit, &d_amount);
    pthread_create(&t2, NULL, withdraw, &w_amount);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final balance : %.2f !\n", balance/100.0);
    return 0;
}