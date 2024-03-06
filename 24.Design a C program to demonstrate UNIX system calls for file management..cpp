#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd; 
    fd = creat("my_file.txt", 0644);
    if (fd == -1) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    printf("File created successfully.\n");

    char data[] = "Hello, world!";
    write(fd, data, sizeof(data));
    printf("Data written to file.\n");

    close(fd);

    fd = open("my_file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead > 0) {
        printf("Read from file: %.*s\n", (int)bytesRead, buffer);
    } else {
        perror("Error reading from file");
    }

    close(fd);

    if (unlink("my_file.txt") == -1) {
        perror("Error deleting file");
        exit(EXIT_FAILURE);
    }
    printf("File deleted successfully.\n");

    return 0;
}