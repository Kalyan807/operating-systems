#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 256 
struct msg_buffer {
    long msg_type;  
    char msg_text[MSG_SIZE];  
};

int main() {
    key_t key = 1234;  
    int msgid;
    struct msg_buffer message;

    if ((msgid = msgget(key, IPC_CREAT | 0666)) < 0) {
        perror("msgget");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        message.msg_type = 1;  
        strcpy(message.msg_text, "Hello from the sender!"); 

        if (msgsnd(msgid, &message, sizeof(message), 0) < 0) {
            perror("msgsnd");
            exit(1);
        }

        printf("Message sent by the sender\n");
    } else {
        wait(NULL);

        if (msgrcv(msgid, &message, sizeof(message), 1, 0) < 0) {
            perror("msgrcv");
            exit(1);
        }

        printf("Message received by the receiver: %s\n", message.msg_text);

        if (msgctl(msgid, IPC_RMID, NULL) < 0) {
            perror("msgctl");
            exit(1);
        }
    }

    return 0;
}