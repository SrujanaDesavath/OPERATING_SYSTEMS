#include <stdio.h>
#include <string.h>

#define MAX 50

int main() {
    char files[MAX][20];
    int count = 0;
    int choice, i;
    char fname[20];

    while(1) {
        printf("\n1. Create File");
        printf("\n2. Delete File");
        printf("\n3. Search File");
        printf("\n4. Display Files");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                if(count >= MAX) {
                    printf("Directory is Full!\n");
                } else {
                    printf("Enter file name: ");
                    scanf("%s", fname);

                    int exists = 0;
                    for(i = 0; i < count; i++) {
                        if(strcmp(files[i], fname) == 0) {
                            exists = 1;
                            break;
                        }
                    }

                    if(exists)
                        printf("File already exists!\n");
                    else {
                        strcpy(files[count], fname);
                        count++;
                        printf("File created successfully.\n");
                    }
                }
                break;

            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", fname);

                for(i = 0; i < count; i++) {
                    if(strcmp(files[i], fname) == 0) {
                        for(int j = i; j < count-1; j++)
                            strcpy(files[j], files[j+1]);
                        count--;
                        printf("File deleted successfully.\n");
                        break;
                    }
                }
                if(i == count)
                    printf("File not found!\n");
                break;

            case 3:
                printf("Enter file name to search: ");
                scanf("%s", fname);

                for(i = 0; i < count; i++) {
                    if(strcmp(files[i], fname) == 0) {
                        printf("File found.\n");
                        break;
                    }
                }
                if(i == count)
                    printf("File not found!\n");
                break;

            case 4:
                printf("\nFiles in Directory:\n");
                for(i = 0; i < count; i++)
                    printf("%s\n", files[i]);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
