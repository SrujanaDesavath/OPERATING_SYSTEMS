#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int source, dest;
    char buffer[100];
    int bytes;

    source = open("source.txt", O_RDONLY);
    if(source < 0){
        printf("Source file not found\n");
        return 1;
    }

    dest = open("dest.txt", O_CREAT | O_WRONLY, 0644);

    while ((bytes = read(source, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }

    printf("File copied successfully\n");

    close(source);
    close(dest);

    return 0;
}
