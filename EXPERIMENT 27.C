#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    char path[100];

    printf("Enter directory path: ");
    scanf("%s", path);

    dir = opendir(path);

    if (dir == NULL) {
        printf("Cannot open directory\n");
        return 0;
    }

    printf("\nFiles:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}
