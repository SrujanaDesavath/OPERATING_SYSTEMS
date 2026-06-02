#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[50], n, head, i, j, total = 0;

    printf("Enter number of requests: ");
    scanf("%d",&n);

    printf("Enter requests: ");
    for(i=0;i<n;i++) scanf("%d",&req[i]);

    printf("Enter head position: ");
    scanf("%d",&head);

    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(req[i] > req[j]) {
                int t = req[i];
                req[i] = req[j];
                req[j] = t;
            }
        }
    }

    for(i=0;i<n;i++) {
        if(req[i] >= head) {
            total += abs(req[i] - head);
            head = req[i];
        }
    }

    for(i=n-1;i>=0;i--) {
        if(req[i] < head) {
            total += abs(req[i] - head);
            head = req[i];
        }
    }

    printf("Total Seek Time = %d\n", total);
}
