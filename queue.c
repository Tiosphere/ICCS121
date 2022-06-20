/* Name: Chiraphat Lua
 * ID: 6381360
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

void push(Queue **q, char *word) {
    printf("PUSH\n");
    if ((*q) == NULL) {
        (*q) = malloc(sizeof(Queue));
        (*q)->head->data = word;
        (*q)->head->next = NULL;
        printf("%c\n", *((*q)->head->data));
        printf("%s\n", (*q)->head->next);
    }
    else if ((*q)->head->next == NULL){
        (*q)->tail->data = word;
        (*q)->tail->next = NULL;
        (*q)->head->next = (*q)->tail;
        printf("%s\n", (*q)->head->next->data);
        printf("%s\n", (*q)->tail->data);
    }
    else {
        Node temp = {.data = word, .next = NULL};
        (*q)->tail->next = &temp;
        (*q)->tail = (*q)->tail->next;
        // (*q)->tail = (Node *) malloc(sizeof(Node));
        (*q)->tail = &temp;
        (*q)->tail->data = word;
        (*q)->tail->next = NULL;
        printf("%s\n", (*q)->head->data);
        printf("%s\n", (*q)->head->next->data);
        printf("%s\n", (*q)->head->next->next->data);
        printf("%s\n", (*q)->tail->data);
        printf("%s\n", (*q)->head->next->next->next);
        printf("%s\n", (*q)->tail->next);
    }
    printf("Adding %c\n", *word);
}

char *pop(Queue *q) {
    char *result = q->head->data;
    q->head = q->head->next;
    return result;
}

void print(Queue *q) {
    printf("PRINT FUNC\n");
    if (q == NULL)
    {
        printf("No items\n");
    }
    else {
        Node *pos = q->head;
        while (1) {
            printf("%s [%s]\n ", pos->data, pos->next->data);
            pos = pos->next;
            if (pos->next == q->tail->next)
            {
                break;
            }
        }
    }
}

int isEmpty(Queue *q) {
    return q == NULL || q->head == NULL;
}

void delete(Queue *q) {

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
    printf("%s\n", q->head->data);
    printf("%s\n", q->head->next);
    printf("%s\n", q->tail);
    push(&q, "b");
    printf("%s\n", q->head->data);
    printf("%s\n", q->tail->data);
    push(&q, "c");
    printf("%s\n", q->head->data);
    printf("%s\n", q->head->next->data);
    printf("%s\n", q->head->next->next->data);
    printf("%s\n", q->tail->data);
    printf("%s\n", q->tail->next);
    push(&q, "F");
    // if (!q->tail->next)
    // {
    //     printf("END\n");
    // }
    // printf("%d\n", q->head->next->next->next);
    // printf("%s\n", q->tail->next);
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
    char *s = (char *)malloc(10);
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