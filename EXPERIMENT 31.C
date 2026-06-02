#include <stdio.h>

int main() {
    int pages[50], frame[10], n, f, i, j, faults = 0, pos = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter pages: ");
    for (i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter frame size: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) frame[i] = -1;

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < f; j++)
            if (frame[j] == pages[i]) found = 1;

        if (!found) {
            frame[pos] = pages[i];
            pos = (pos + 1) % f;
            faults++;
        }
    }

    printf("Page Faults = %d\n", faults);
}
