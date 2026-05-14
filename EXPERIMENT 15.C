#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_FILES 20

struct User {
    char uname[20];
    char files[MAX_FILES][20];
    int fileCount;
};

int main() {
    struct User users[MAX_USERS];
    int userCount = 0;
    int choice, i, j;
    char uname[20], fname[20];

    while(1) {
        printf("\n1. Create User");
        printf("\n2. Create File");
        printf("\n3. Display Directory");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter user name: ");
            scanf("%s", uname);

            strcpy(users[userCount].uname, uname);
            users[userCount].fileCount = 0;
            userCount++;
            printf("User created successfully.\n");
            break;

        case 2:
            printf("Enter user name: ");
            scanf("%s", uname);

            for(i = 0; i < userCount; i++) {
                if(strcmp(users[i].uname, uname) == 0) {
                    printf("Enter file name: ");
                    scanf("%s", fname);

                    strcpy(users[i].files[users[i].fileCount], fname);
                    users[i].fileCount++;
                    printf("File created successfully under %s.\n", uname);
                    break;
                }
            }

            if(i == userCount)
                printf("User not found!\n");
            break;

        case 3:
            printf("\nDirectory Structure:\n");
            for(i = 0; i < userCount; i++) {
                printf("User: %s\n", users[i].uname);
                for(j = 0; j < users[i].fileCount; j++)
                    printf("   %s\n", users[i].files[j]);
            }
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
