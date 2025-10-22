#include <stdio.h>
#include <pthread.h>

int counter = 0;  // Shared variable

void* increment(void* arg) {
    for (int i = 0; i < 100000; i++) {
        counter++;  // Race condition!
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("Counter: %d\n", counter);  // Should be 200000, but won't be!
    return 0;
}