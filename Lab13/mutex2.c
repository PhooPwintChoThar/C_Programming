#include<stdio.h>
#include<pthread.h>

int buffer;
int available=0;
pthread_mutex_t mlock= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cond= PTHREAD_COND_INITIALIZER;

void* producer (void* arg){
    
    for(int i =0; i<10; i++){
        pthread_mutex_lock(&mlock);
        while(available){
            pthread_cond_wait(&cond, &mlock);
        }

        buffer =i;
        available=1;
        printf("Produced : %d !\n", buffer);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mlock);
    }
    return NULL;
}

void* consumer (void* arg){
    
    for(int i =0; i<10; i++){
        pthread_mutex_lock(&mlock);
        while(!available){
            pthread_cond_wait(&cond, &mlock);
        }
        available=0;
        printf("Consumed : %d !\n", buffer);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mlock);
    }
    return NULL;
}


int main(){
    pthread_t p,c;
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
    return 0;
}