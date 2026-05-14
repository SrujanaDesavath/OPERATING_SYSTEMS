#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main() {
    int shmid;
    char *str;

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);

    if (fork() == 0) {  // Child Process
        sleep(1);  // wait for parent to write
        str = (char*) shmat(shmid, NULL, 0);
        printf("Child reads: %s\n", str);
        shmdt(str);
    } else {  // Parent Process
        str = (char*) shmat(shmid, NULL, 0);
        strcpy(str, "Hello from Parent using Shared Memory!");
        printf("Parent wrote message.\n");
        shmdt(str);
    }

    return 0;
}
