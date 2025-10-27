#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_ORDERS 5
#define TOTAL_ORDERS 10

typedef struct {
    int order_id;
    char item[20];
} Order;

Order order_queue[MAX_ORDERS];
int queue_count = 0;
int queue_front = 0;
int queue_rear = 0;
int next_order_id = 1;
int cooked = 0;
int delivered = 0;

pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t queue_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t queue_not_empty = PTHREAD_COND_INITIALIZER;

int is_queue_full() {
    return queue_count == MAX_ORDERS;
}

int is_queue_empty() {
    return queue_count == 0;
}

void add_order(Order o) {
    order_queue[queue_rear] = o;
    queue_rear = (queue_rear + 1) % MAX_ORDERS;
    queue_count++;
}

Order take_order() {
    Order o = order_queue[queue_front];
    queue_front = (queue_front + 1) % MAX_ORDERS;
    queue_count--;
    return o;
}

void* chef(void *arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_mutex_lock(&queue_mutex);
        if (cooked >= TOTAL_ORDERS) {
            pthread_mutex_unlock(&queue_mutex);
            break;
        }
        while (is_queue_full()) {
            pthread_cond_wait(&queue_not_full, &queue_mutex);
        }
        Order o;
        o.order_id = next_order_id++;
        strcpy(o.item, (o.order_id % 2 == 0) ? "Pizza" : "Burger");
        add_order(o);
        cooked++;
        printf("[CHEF-%d] Cooking Order #%d: %s\n", id, o.order_id, o.item);
        pthread_cond_signal(&queue_not_empty);
        pthread_mutex_unlock(&queue_mutex);
        sleep(1);
    }
    return NULL;
}

void* waiter(void *arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_mutex_lock(&queue_mutex);
        if (delivered >= TOTAL_ORDERS) {
            pthread_mutex_unlock(&queue_mutex);
            break;
        }
        while (is_queue_empty()) {
            pthread_cond_wait(&queue_not_empty, &queue_mutex);
        }
        Order o = take_order();
        delivered++;
        printf("[WAITER-%d] Delivered Order #%d: %s\n", id, o.order_id, o.item);
        pthread_cond_signal(&queue_not_full);
        pthread_mutex_unlock(&queue_mutex);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t chefs[2], waiters[3];
    int id1 = 1, id2 = 2, id3 = 3, id4 = 4, id5 = 5;

    pthread_create(&chefs[0], NULL, chef, &id1);
    pthread_create(&chefs[1], NULL, chef, &id2);

    pthread_create(&waiters[0], NULL, waiter, &id3);
    pthread_create(&waiters[1], NULL, waiter, &id4);
    pthread_create(&waiters[2], NULL, waiter, &id5);

    for (int i = 0; i < 2; i++) pthread_join(chefs[i], NULL);
    for (int i = 0; i < 3; i++) pthread_join(waiters[i], NULL);

    return 0;
}
