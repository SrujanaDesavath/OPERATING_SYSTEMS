#include <stdio.h>
#include <stdlib.h>

struct emp {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct emp e;
    int choice, id;

    while(1) {
        printf("\n1. Add Employee");
        printf("\n2. Display Employee");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            fp = fopen("employee.dat", "ab+");
            if(fp == NULL) {
                printf("File cannot be opened!\n");
                exit(1);
            }

            printf("Enter Employee ID: ");
            scanf("%d", &e.id);
            printf("Enter Name: ");
            scanf("%s", e.name);
            printf("Enter Salary: ");
            scanf("%f", &e.salary);

            fwrite(&e, sizeof(e), 1, fp);
            printf("Employee record added successfully.\n");

            fclose(fp);
            break;

        case 2:
            fp = fopen("employee.dat", "rb");
            if(fp == NULL) {
                printf("File not found!\n");
                break;
            }

            printf("Enter Employee ID to search: ");
            scanf("%d", &id);

            fseek(fp, (id - 1) * sizeof(e), SEEK_SET);
            fread(&e, sizeof(e), 1, fp);

            if(e.id == id) {
                printf("\nEmployee Details:\n");
                printf("ID: %d\n", e.id);
                printf("Name: %s\n", e.name);
                printf("Salary: %.2f\n", e.salary);
            } else {
                printf("Record not found!\n");
            }

            fclose(fp);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}
