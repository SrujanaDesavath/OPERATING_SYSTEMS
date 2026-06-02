#include <stdio.h>

int main() {
    int pages[50], frame[10], time[10];
    int n, f, i, j, faults = 0, counter = 0, pos;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter pages: ");
    for (i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter frame size: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) frame[i] = -1;

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
            }
        }

        if (!found) {
            pos = 0;
            for (j = 1; j < f; j++)
                if (time[j] < time[pos]) pos = j;

            frame[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }
    }

    printf("Page Faults = %d\n", faults);
}
