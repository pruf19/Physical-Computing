#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Record {
    char id[10];
    char name[100];
    long salary;
    long sales;
    struct Record *next;
}Record;
 
typedef struct SinglyLinkedList {
    unsigned int count;
    Record* head;
} SinglyLinkedList; 
 
 
Record *createRecord(char *id, char *name, long salary, long sales){
    Record *newRecord = (Record*) malloc(sizeof(Record));
    strcpy(newRecord->id,id);
    strcpy(newRecord->name, name);
    newRecord->salary = salary;
    newRecord->sales  = sales;
    newRecord->next = NULL; 
    return newRecord;
}
 
 
void findId(SinglyLinkedList* list,char *target){
    if (list->count == 0) {
        printf("ID not found !!!");
        return;
    }
    Record* pointer = list->head;
    while (pointer != NULL) {
        if(strcmp(pointer->id,target) == 0){
            double commission = (double)pointer->sales * 2 / 100.0;
            printf("%s\n%s\n%ld\n%.2f\n%ld\n%.2f", pointer->id, pointer->name, 
                    pointer->sales, commission, pointer->salary, pointer->salary + commission);
            return;
        }
        pointer = pointer->next;
    }
    printf("ID not found !!!");
}
 
void insert(SinglyLinkedList* list, char *id, char *name, long salary, long sales) {
    Record* pNew = createRecord(id, name, salary, sales);
    if (list->count == 0) {
        list->head = pNew;
    } 
    else {
        Record* pointer = list->head;
        while (pointer->next != NULL){
            pointer = pointer->next;
        }
        pointer->next = pNew;
    }
    list->count++;
}
 
SinglyLinkedList* createSinglyLinkedList() {
    SinglyLinkedList* list = (SinglyLinkedList*) malloc(sizeof(SinglyLinkedList));
    list->count = 0;
    list->head = NULL;
    return list;
}
 
int main(){
    long salary,sales;
    int num;
    char id[10],name[100],target[10];
    SinglyLinkedList* mylist = createSinglyLinkedList();
 
    scanf("%d",&num);
    for(int i = 0; i < num;i++){
        scanf("%s %s %ld %ld",id,name,&salary,&sales);
        insert(mylist, id, name, salary, sales);
    }
    scanf("%s",target);
    findId(mylist,target);
    Record *current = mylist->head;
    while (current != NULL) {
        Record* temp = current;
        current = current->next;
        free(temp);
    }
    free(mylist);
    return 0;
}
