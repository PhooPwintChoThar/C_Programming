#include <stdio.h>
#include <pthread.h>

void* printHello(void* arg) {
    int id = *(int*)arg;
    printf("Hello from thread %d\n", id);
    return NULL;
}

int main() {
    pthread_t thread;
    int id = 1;
    
    pthread_create(&thread, NULL, printHello, &id);
    pthread_join(thread, NULL);
    
    printf("Thread finished\n");
    return 0;
}