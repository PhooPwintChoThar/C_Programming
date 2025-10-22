#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int balance=5000;
int transaction_count=0;
pthread_mutex_t mlock;
int second_account=0;


void* deposit(void* arg){

    int amount= 1000;
    
    for(int i=0; i<3 ; i++){
        sleep(3);
        pthread_mutex_lock(&mlock);
        printf("Processing....\n");
        balance+=amount;
        transaction_count+=1;
        printf("Proceeded deposit 1000 ; Your  balance : %d \n", balance);
        pthread_mutex_unlock(&mlock);
    }  
   
    

    return NULL;

}

void* withdraw(void* arg){

    int amount= 500;
    
    for(int i=0; i<4 ; i++){
        sleep(3);
        pthread_mutex_lock(&mlock);
        printf("Processing....\n");
        balance-=amount;
        transaction_count+=1;
        printf("Proceeded withdrawl 500 ; Your  balance : %d \n", balance);
        pthread_mutex_unlock(&mlock);
    }  
   
    

    return NULL;

}

void* check_balance(void* arg){
    for(int i=0; i<2; i++){
        sleep(3);
        pthread_mutex_lock(&mlock);
        printf("Checking balance....\n");
        printf("Your balance is : %d\n", balance);
        pthread_mutex_unlock(&mlock);

    }
    
    return NULL;

}

void* transfer(void* arg){

        pthread_mutex_lock(&mlock);
        printf("Processing Transfer ....\n");
        sleep(3);
        printf("Your balance in second account  before transfer is  : %d\n", second_account);
        second_account+=balance;
        balance=0;
        printf("Your balance is now : %d\n", balance);
        printf("Your balance in second account is now : %d\n", second_account);
        pthread_mutex_unlock(&mlock);

    
    
    return NULL;

}


int main(){
    pthread_t threads[3];

    pthread_mutex_init(&mlock, NULL);
    pthread_create(&threads[0], NULL, deposit, NULL);
    pthread_create(&threads[1], NULL, withdraw, NULL);
    pthread_create(&threads[2], NULL, check_balance, NULL);

    for(int i=0; i<3; i++){
        pthread_join(threads[i], NULL);
    }

    
    printf("FINAL BALANCE : %d\n", balance);
    printf("TOTAL TRANSACTIONs : %d\n", transaction_count);

    //bonus
    pthread_t t;
    pthread_create(&t, NULL, transfer, NULL);
    pthread_join(t, NULL);
    pthread_mutex_destroy(&mlock);
    return 0;
}
