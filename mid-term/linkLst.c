#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DEBUG 0

struct my_node{
        char *i; // Your data that you want to store
        struct my_node * next; // The pointer to the next node
};

typedef struct my_node Node;

Node * first; // point to the first element in my linked list

void deleteAt(int index)
{
        int counter = 0;
        Node *temp, *temp2=NULL;
        if(first==NULL) return;
        for(temp=first; (temp!=NULL) && (counter<index); temp = temp->next)
        {
                temp2=temp;
                counter++;
        }
        if(temp2==NULL)
        {
                first = temp->next;
                free(temp);
        }
        else if(temp!=NULL)
        {
                temp2->next = temp->next;
                free(temp);
        }
        return;
}

void insertAt(int index,char *data)
{
        int counter = 0;
        if(DEBUG) printf("Inserting at index %d, data = %d, first is at %x\n", index, data, first);
        Node * temp2=NULL;
        Node * temp =first;
        for(; (temp!=NULL) && (counter<index); temp = temp->next)
        {
                if(DEBUG) printf("Looping through our list, at index %d, data is %d\n", counter, temp->i);
                temp2 = temp;
                counter++;
        }
        // Example, if index is 2
        // A -> (temp2 points here) B -> (insert at index 2, temp points to C) C -> D
        // Now that temp2 points to B, temp points to C. We want to insert after B
        Node * temp3 = malloc(sizeof(Node));
        temp3->i = data;
        if(temp2 == NULL)
        {
                temp3->next = first;
                first = temp3;
        }
        else
        {
                temp3->next = temp; // The new node->next points to C
                temp2->next = temp3; // B-> next point to the new node
        }
}

void print()
{
        for(Node * temp = first; temp!=NULL ; temp = temp->next)
        {
                printf("%s, ", temp->i);
        }
        printf("\n");
}

int getSize(Node * list)
{
        int size=0;
        for(Node * temp = first; temp!=NULL ; temp = temp->next)
                size++;
        return size;
}
int compFunc(char *a, char *b){
        int sumA = 0;
        int sumB = 0;
        for (int i = 0; i < strlen(a); i++)
        {
                sumA += (int) a[i];
        }
        for (size_t i = 0; i < strlen(b); i++)
        {
                sumB += (int) b[i];
                if (sumA < sumB){return -1;}
        }
        if (sumA == sumB){return 0;}
        else{return 1;}
}
int countPop(char * input) {
        int result = 0;
        for(Node * temp = first; temp!=NULL ; temp = temp->next)
        {
                if (compFunc(input, temp->i) < 0){result++;}
        }
        return result;
}

int main(int argc, char* argv[])
{
        insertAt(0, "5");
        insertAt(1, "last");
        insertAt(1, "20");
        insertAt(0, "first");
        print();
        printf("Size of linkedlist is %d\n",getSize(first));
        deleteAt(3);
        print();
        printf("Size of linkedlist is %d\n",getSize(first));
        deleteAt(0);
        print();
        printf("Size of linkedlist is %d\n",getSize(first));
        deleteAt(1000);
        print();
        printf("Size of linkedlist is %d\n",getSize(first));
        deleteAt(0);
        print();
        printf("Size of linkedlist is %d\n",getSize(first));
        deleteAt(0);
        print();
        printf("Size of linkedlist is %d\n",getSize(first));
        insertAt(0, "a");
        insertAt(1, "ap");
        insertAt(2, "app");
        insertAt(3, "apple");
        insertAt(4, "apples");
        print();
        printf("Size of linkedlist is %d\n",getSize(first));
        printf("There are %d more words bigger than \"a\"\n", countPop("a"));
        printf("There are %d more words bigger than \"app\"\n", countPop("app"));
        return 0;
}
