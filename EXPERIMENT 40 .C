#include <stdio.h>

int main() {
    int choice;

    printf("1.Owner 2.Group 3.Others\n");
    scanf("%d",&choice);

    if(choice==1)
        printf("Owner: rwx = 7\n");
    else if(choice==2)
        printf("Group: r-x = 5\n");
    else
        printf("Others: r-- = 4\n");
}
