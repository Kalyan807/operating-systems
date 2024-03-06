#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd = open("sample.txt", O_RDWR);
    
    close(fd);

    FILE *file = fopen("sample.txt", "r");
    fseek(file, 10, SEEK_SET);
    fclose(file);

    struct stat file_info;
    stat("sample.txt", &file_info);
    printf("File size: %ld bytes\n", file_info.st_size);

    DIR *dir = opendir(".");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("File: %s\n", entry->d_name);
    }
    closedir(dir);

    return 0;
}