#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

// Structure for message
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    int msgid;
    struct msg_buffer message;

    // Create message queue
    msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);

    if (fork() == 0) {   // Child Process
        msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
        printf("Child received: %s\n", message.msg_text);
    } 
    else {   // Parent Process
        message.msg_type = 1;
        strcpy(message.msg_text, "Hello from Parent using Message Queue!");
        msgsnd(msgid, &message, sizeof(message.msg_text), 0);
        printf("Parent sent message.\n");
    }

    return 0;
}
