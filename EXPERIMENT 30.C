#include <stdio.h>
#include <pthread.h>

void* fun(void* arg) {
    printf("Thread executing\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, fun, NULL);
    pthread_create(&t2, NULL, fun, NULL);

    if (pthread_equal(t1, t2))
        printf("Equal threads\n");
    else
        printf("Not equal threads\n");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Threads completed\n");
}
