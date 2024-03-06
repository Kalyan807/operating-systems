#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(-1);
    } else if (pid == 0) {
        execlp("/bin/ls", "ls", "-l", NULL);
    } else {
        wait(NULL);
        printf("\nChild process complete.\n");
    }
    return 0;
}