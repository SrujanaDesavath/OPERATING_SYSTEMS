#include <stdio.h>

int main() {
    int blockSize[20], processSize[20];
    int m, n, i, j, bestIdx, allocation[20];

    printf("Enter number of blocks: ");
    scanf("%d", &m);

    printf("Enter block sizes:\n");
    for(i=0;i<m;i++) scanf("%d",&blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter process sizes:\n");
    for(i=0;i<n;i++) scanf("%d",&processSize[i]);

    for(i=0;i<n;i++) allocation[i] = -1;

    for(i=0;i<n;i++) {
        bestIdx = -1;
        for(j=0;j<m;j++) {
            if(blockSize[j] >= processSize[i]) {
                if(bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }

        if(bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for(i=0;i<n;i++) {
        printf("%d\t%d\t", i+1, processSize[i]);
        if(allocation[i]!=-1) printf("%d\n", allocation[i]+1);
        else printf("Not Allocated\n");
    }
}
