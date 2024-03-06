#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dynamic_variable;
    dynamic_variable = (int *)malloc(sizeof(int)); 
    if (dynamic_variable == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    *dynamic_variable = 10;  
    printf("Dynamic variable: %d\n", *dynamic_variable);
    free(dynamic_variable);  
    return 0;
}