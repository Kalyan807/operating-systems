#include <stdio.h>

int main() {
    FILE *file = fopen("my_file.txt", "w"); 
    if (file) {
        fprintf(file, "Hello, world!\n");
        fclose(file);
    } else {
        printf("Error opening file.\n");
    }
    return 0;
}