#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Book {
    char id[10];
    char name[100];
    char author[100];
}book;
 
int main(){
    int num;
    char find_id[10];
 
    scanf("%d",&num);
    scanf("%s",find_id);
 
    book *listbook[num];
 
    for (int i = 0; i < num;i++){
        listbook[i] = malloc(sizeof(book)); 
        scanf("%s %s %s",listbook[i]->id,listbook[i]->name,listbook[i]->author);
    }
    int found = 0;
    for (int i = 0; i < num; i++) {
        if (strcmp(listbook[i]->id, find_id) == 0) {
            printf("%s %s %s\n", listbook[i]->id, listbook[i]->name, listbook[i]->author);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Not Found\n");
    }
 
    for (int i = 0; i < num; i++) {
        free(listbook[i]);
    }
    return 0;
}
