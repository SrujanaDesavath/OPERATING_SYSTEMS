#include <stdio.h>

int main() {
    int pages[50], frame[10], n, f, i, j, k, faults = 0;

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
            int far = -1, pos = -1;
            for (j = 0; j < f; j++) {
                for (k = i + 1; k < n; k++)
                    if (frame[j] == pages[k]) break;

                if (k > far) {
                    far = k;
                    pos = j;
                }
            }
            frame[pos] = pages[i];
            faults++;
        }
    }

    printf("Page Faults = %d\n", faults);
}
