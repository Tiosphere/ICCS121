/* Name: Chiraphat Lua
 * ID: 6381360
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

void push(Queue **q, char *word) {
    Node *temp = malloc(sizeof(Node));
    temp->data = word;
    temp->next = NULL;
    if((*q) == NULL){
        (*q) = malloc(sizeof(Node *) * 2);
        (*q)->head = temp;
    }
    else if ((*q)->head == NULL){
        (*q)->head = temp;
    }
    else if ((*q)->head->next == NULL){
        (*q)->head->next = temp;
        (*q)->tail = temp;
    }
    else{
        (*q)->tail->next = temp;
        (*q)->tail = (*q)->tail->next;
    }
}

char *pop(Queue *q) {
    if(q->head == NULL){
        return NULL;
    }
    char *word = malloc(strlen(q->head->data) + 1);
    strcpy(word, q->head->data);
    Node *temp = q->head;
    q->head = q->head->next;
    free(temp);
    return word;
}

void print(Queue *q) {
    if(q == NULL || q->head == NULL){printf("No items\n");}
    else{
        Node *pos = q->head;
        while (pos != NULL){
            printf("%s\n", pos->data);
            pos = pos->next;
        }
    }

}

int isEmpty(Queue *q) {
    return q == NULL || q->head == NULL;
}

void delete(Queue *q) {
    while (q->head != NULL){
        Node *temp = q->head;
        q->head = q->head->next;
        free(temp);
    }
    q = NULL;
}

/***** Expected output: *****
No items
a
b
c
a
b
c
d
e
f
No items
s = World
t = Hello
*****************************/
int main(int argc, char **argv)
{
    Queue *q = NULL;
    // print the queue
    print(q);

    // push items
    push(&q, "a");
    push(&q, "b");
    push(&q, "c");
    print(q);

    // pop items
    while (!isEmpty(q)) {
        char *item = pop(q);
        printf("%s\n", item);
        free(item);
    }

    char *item = pop(q);
    assert(item == NULL);

    // push again
    push(&q, "d");
    push(&q, "e");
    push(&q, "f");
    print(q);

    // destroy the queue
    delete(q);

    // print again
    print(q);

    // check copy
    char *s = (char *) malloc(10);
    strcpy(s, "Hello");
    push(&q, s);
    strcpy(s, "World");
    char *t = pop(q);
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    free(t);
    free(s);

    // free the queue
    free(q);
}