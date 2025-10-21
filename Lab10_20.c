#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
   
// DataNode structure using typedef
typedef struct DataNode {
  char* data;
  struct DataNode* next;
} DataNode;
   
// SinglyLinkedList structure using typedef
typedef struct SinglyLinkedList {
  unsigned int count;
  DataNode* head;
} SinglyLinkedList; 
   
DataNode* createDataNode(char* data);
   
// Create a new DataNode
DataNode* createDataNode(char* data) {
  // Allocate memory for the node
  DataNode* newNode = (DataNode*)malloc(sizeof(DataNode));
   
  // Allocate memory for the string and copy the data
  newNode->data = (char*)malloc(strlen(data) + 1);
  strcpy(newNode->data, data);
   
  newNode->next = NULL;
  return newNode;
}
   
// Function prototypes
DataNode *createDataNode(char *data);
SinglyLinkedList *createSinglyLinkedList();
void traverse(SinglyLinkedList *list);
void insert_last(SinglyLinkedList *list, char *data);
   
// Create a new SinglyLinkedList
SinglyLinkedList* createSinglyLinkedList() {
    SinglyLinkedList *new_list = malloc(sizeof(SinglyLinkedList));
    new_list->count = 0;
    new_list->head = NULL;
    return new_list;
}
// Traverse the list and print data
void traverse(SinglyLinkedList* list) {
    if (list->count == 0) {
        printf("This is an empty list.\n");
        return;
    }
    struct DataNode* pointer = list->head;
    while (pointer->next != NULL) {
        printf("%s -> ", pointer->data); // ปริ้นข้อมูลและขยับ pointer ไปเรื่อยๆ จนถึงโหนดตัวสุดท้าย
        pointer = pointer->next;
    }
    printf("%s\n", pointer->data);
}
   
// Insert a new node at the end of the list
void insert_last(SinglyLinkedList* list, char* data) {
    struct DataNode* pNew = createDataNode(data);
    if (list->count == 0) {
        list->head = pNew;//ถ้า Linked List ว่างให้เปลี่ยนตำแหน่ง list->head ไปที่ pNew
    } else {
        DataNode *pointer = list->head; // ถ้า Linked List ไม่ว่างให้สร้าง Pointer ตัวใหม่และขยับไปที่โหนดสุดท้ายและเปลี่ยน pointer->next เป็น pNew
        while (pointer->next != NULL)
        {
           pointer = pointer->next;
        }
        pointer->next = pNew;
    }
    list->count++;
}
   
int main() {
    SinglyLinkedList* list = createSinglyLinkedList();
    SinglyLinkedList* ans = createSinglyLinkedList();
    int n;
    char *data = malloc(20);
    scanf("%d", &n);
   
    for (int i = 0; i < n; i++)
    {
        scanf("%s", data);
        insert_last(list, data);
    }
  
    int a,b;
    for (int i = 0; i < floor(n/2.0); i++)
    {
        if (i%2 == 0){
            a = n+(-i-1);
            b = i;
        }
        else {
            a = i;
            b = n+(-i-1);
        }
        DataNode *p = list->head;
        for (int j = 0; j < a; j++){
            p = p->next;
        }
        insert_last(ans, p->data);
        DataNode *pointer = list->head;
        for (int j = 0; j < b; j++){
            pointer = pointer->next;
        }
        insert_last(ans, pointer->data);
    }
    if (n%2 != 0){
        DataNode *pointer = list->head;
        for (int i = 0; i < floor(n/2.0); i++){
            pointer = pointer->next;
        }
        insert_last(ans, pointer->data);
    }
    traverse(ans);
   
    // Remember to free allocated memory for each node's data
    DataNode *current = list->head;
    while (current != NULL) {
        free(current->data);
        DataNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
  
    DataNode *cur = ans->head;
    while (cur != NULL) {
        free(cur->data);
        DataNode* temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(ans);
    return 0;
}
