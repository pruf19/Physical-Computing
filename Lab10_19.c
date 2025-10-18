#include <stdio.h>
#include <stdlib.h>
#include <string.h>
   
typedef struct DataNode {
    char* data;
    struct DataNode* next;
} DataNode;
   
typedef struct SinglyLinkedList {
  int count;
  DataNode* head;
} SinglyLinkedList; 
   
DataNode *createDataNode(char *data);
SinglyLinkedList *createSinglyLinkedList();
void traverse(SinglyLinkedList *list,int index);
void insert_last(SinglyLinkedList *list, char *data);
   
int main() {
    SinglyLinkedList* mylist = createSinglyLinkedList();
    char *data = (char*) malloc(20 * sizeof(char));
    int index;
     
    while (1){
        scanf("%s",data);
        if (strcmp(data,"Last") == 0){
            break;
        }
        else{
            insert_last(mylist,data);
        }
    }
    scanf("%d",&index);
    traverse(mylist,index);
     
  
    DataNode* current = mylist->head;
    while (current != NULL) {
        free(current->data);
        DataNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(mylist);
    return 0;
}
   
DataNode* createDataNode(char* data){
    DataNode* newNode = (DataNode*) malloc(sizeof(DataNode));
    newNode->data = (char*) malloc(strlen(data)+1);
   
    strcpy(newNode->data, data);
    newNode->next = NULL;
   
    return newNode;
   
}
 
 
SinglyLinkedList* createSinglyLinkedList() {
    SinglyLinkedList* list = (SinglyLinkedList*) malloc(sizeof(SinglyLinkedList));
    list->count = 0;
    list->head = NULL;
    return list;
}
   
void traverse(SinglyLinkedList* list,int index) {
    if (list->count == 0 || index >= list->count || index < -((int)list->count)) {
        printf("Error\n");
        return;
    }
    if (index < 0) {
        index = list->count + index;
    }
    DataNode* pointer = list->head;
    for (int i = 0; i < index; i++) {
        pointer = pointer->next;
    }
    printf("%s\n", pointer->data);
 
     
}
  
void insert_last(SinglyLinkedList* list, char* data) {
    struct DataNode* pNew = createDataNode(data);
    if (list->count == 0) {
        list->head = pNew;
    } else {
        struct DataNode* pointer = list->head;
        while (pointer->next != NULL){
            pointer = pointer->next;
        }
        pointer->next = pNew;
    }
    list->count++;
}
