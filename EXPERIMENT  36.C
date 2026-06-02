#include <stdio.h>

int main() {
    int blocks[20], n, i;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");
    for(i=0;i<n;i++)
        scanf("%d",&blocks[i]);

    printf("Linked Allocation:\n");

    for(i=0;i<n-1;i++)
        printf("%d -> ", blocks[i]);

    printf("%d -> NULL", blocks[n-1]);
}
