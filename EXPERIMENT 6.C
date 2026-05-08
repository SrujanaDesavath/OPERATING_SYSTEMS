#include <stdio.h>

int main() {
    int n, i, time = 0, count = 0;
    int at[10], bt[10], pr[10], rt[10];
    int ct[10], tat[10], wt[10];
    int min, index;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nP%d Arrival Time: ", i+1);
        scanf("%d", &at[i]);
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
        printf("P%d Priority: ", i+1);
        scanf("%d", &pr[i]);
        rt[i] = bt[i];   // remaining time
    }

    while(count < n) {
        min = 9999;
        index = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && pr[i] < min) {
                min = pr[i];
                index = i;
            }
        }

        if(index != -1) {
            rt[index]--;
            time++;

            if(rt[index] == 0) {
                ct[index] = time;
                count++;
            }
        } else {
            time++;
        }
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i],
               ct[i], tat[i], wt[i]);
    }

    return 0;
}
