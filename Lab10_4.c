#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main() {
    char text[151];
    char *word;
    int count = 0;
 
    // รับข้อความ 1 บรรทัด
    scanf(" %[^\n]", text);
 
    // นับจำนวนคำ
    char temp[151];
    strcpy(temp, text); // สำเนาข้อความไว้สำหรับนับ
    word = strtok(temp, " ");
    while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }
 
    // แสดงจำนวนคำ
    printf("%d words\n", count);
    printf("----\n");
 
    // แสดงแต่ละคำ (แปลงเป็นตัวพิมพ์เล็ก + แสดงจำนวนตัวอักษร)
    word = strtok(text, " ");
    while (word != NULL) {
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            word[i] = tolower(word[i]);
        }
        printf("%s : %d\n", word, len);
        word = strtok(NULL, " ");
    }
 
    return 0;
}
