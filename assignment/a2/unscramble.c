#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int cmpfunc(const void *a, const void *b) {
  return *(char*)a - *(char*)b;
}

int dict_reader(const char *dic_file, char *dict[], char *dict_sort[]) {
    FILE* dic = fopen(dic_file, "r");
    int i = 0;
    char ch[51];
    while (fscanf(dic, "%s", ch) == 1)
    {
        int size = strlen(ch);
        dict[i] = malloc(size + 1);
        dict_sort[i] = malloc(size + 1);
        dict[i] = strcpy(dict[i], ch);
        qsort(ch, size, sizeof(char), cmpfunc);
        dict_sort[i] = strcpy(dict_sort[i], ch);
        i++;
    }
    return i;
}

void checker(const char *jum_file, char *dict[], char *dict_sort[], int dict_size) {
    FILE* jum = fopen(jum_file, "r");
    char ch[51];
    while (fscanf(jum, "%s", ch) == 1) {
        size_t size = strlen(ch);
        printf("%s:", ch);
        qsort(ch, size, (size_t) sizeof(char), cmpfunc);
        int found = 0;
        for (int i = 0; i < dict_size; i++)
        {
            if (size == strlen(dict[i]) && strcmp(ch, dict_sort[i]) == 0)
            {
                printf(" %s", dict[i]);
                found++;
            }
        }
        if (found){printf("\n");}
        else {printf(" NO MATCHES\n");}
    }
}

int main(int argc, char const *argv[])
{
    char *dict[500000];
    char *dict_sort[500000];
    int size = dict_reader(argv[1], dict, dict_sort);
    checker(argv[2], dict, dict_sort, size);
    return argc;
}