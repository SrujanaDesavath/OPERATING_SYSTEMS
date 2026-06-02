#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;

void producer() {
    if (mutex == 1 && empty != 0) {
        mutex = 0;
        x++;
        printf("Produced item %d\n", x);
        full++;
        empty--;
        mutex = 1;
    } else {
        printf("Buffer Full\n");
    }
}

void consumer() {
    if (mutex == 1 && full != 0) {
        mutex = 0;
        printf("Consumed item %d\n", x);
        x--;
        full--;
        empty++;
        mutex = 1;
    } else {
        printf("Buffer Empty\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: producer(); break;
            case 2: consumer(); break;
            case 3: exit(0);
        }
    }
}
