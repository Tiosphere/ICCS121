/* Name:
 * ID:
 */
#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"

void sort(Entry **in, int nL, void *comparator) {
    // IMPLEMENT
    for(int i = 0; i < nL; i++){
        printf("%d %s\n", in[i]->data, &in[i]->name);
    }
}

int compare(Entry a, Entry b) {
    // IMPLEMENT
}

/*
TEST: ./mergesort < test.in
OUTPUT:
1 lsdfjl
2 ghijk
3 ksdljf
5 abc
6 def
*/
int main(void) {
    // IMPLEMENT
    int size;
    scanf("%d", &size);
    Entry *lst[size];
    for(int i = 0; i < size; i++){
        Entry *temp = malloc(sizeof(Entry));
        scanf("%d %s", &temp->data, &temp->name);
        // printf("%d %s\n", temp->data, &temp->name);
        lst[i] = temp;
    }
    
    sort(lst, size, compare);
}
