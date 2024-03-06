#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, argv[2])) {
            printf("%s", line);
        }
    }
    fclose(file);
    return 0;
}