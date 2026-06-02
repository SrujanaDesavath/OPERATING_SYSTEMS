#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char file[50], word[20], line[200];

    printf("Enter file name: ");
    scanf("%s", file);

    printf("Enter word: ");
    scanf("%s", word);

    fp = fopen(file, "r");

    if (fp == NULL) {
        printf("File not found\n");
        return 0;
    }

    printf("\nMatching lines:\n");
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, word))
            printf("%s", line);
    }

    fclose(fp);
}
