#include <stdio.h>
#include <pthread.h>

int num;

void* square(void* arg) {
    printf("Square of %d = %d\n", num, num * num);
    return NULL;
}

void* cube(void* arg) {
    printf("Cube of %d = %d\n", num, num * num * num);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    printf("Enter a number: ");
    scanf("%d", &num);

    pthread_create(&t1, NULL, square, NULL);
    pthread_create(&t2, NULL, cube, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread finished.\n");

    return 0;
}
