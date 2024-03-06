#include <stdio.h>

int main() {
    int pages[] = {1, 2, 3, 4, 5}; 
    int capacity = 3; 
    int frames[capacity];
    int page_faults = 0;

    for (int i = 0; i < capacity; i++) {
        frames[i] = -1; 
    }

    for (int i = 0; i < 5; i++) {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < capacity; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[page_faults % capacity] = page;
            page_faults++;
        }
    }

    printf("Number of page faults: %d\n", page_faults);
    return 0;
}