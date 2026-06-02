#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[50], n, head, i, total = 0;

    printf("Enter number of requests: ");
    scanf("%d",&n);

    printf("Enter requests: ");
    for(i=0;i<n;i++) scanf("%d",&req[i]);

    printf("Enter head position: ");
    scanf("%d",&head);

    for(i=0;i<n;i++) {
        total += abs(req[i] - head);
        head = req[i];
    }

    printf("Total Seek Time = %d\n", total);
}
