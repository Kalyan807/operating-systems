#include <stdio.h>
#define N 5
#define M 3

int isSafe(int processes[], int available[], int max[][M], int allocation[][M]) {
    
}

int main() {
    if (isSafe(int processes,int available,int max,int allocation)) {
   
        printf("Resources allocated safely.\n");
    } else {
        printf("Resource allocation would lead to a deadlock. Waiting...\n");
    }
    
    return 0;
}