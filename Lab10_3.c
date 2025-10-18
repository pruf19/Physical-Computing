#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main() {
    char target;
    char text[151];
    int count = 0;
 
    // รับตัวอักษรที่ต้องการค้นหา
    scanf("%c", &target);
 
    // รับข้อความ 1 บรรทัด (จนกว่าจะเจอ \n)
    scanf(" %[^\n]", text);
 
    // ทำให้ตัวอักษรเป้าหมายเป็นพิมพ์เล็ก
    target = tolower(target);
 
    // วนลูปนับจำนวนตัวอักษร
    for (int i = 0; text[i] != '\0'; i++) {
        if (tolower(text[i]) == target) {
            count++;
        }
    }
 
    // แสดงผล
    printf("%d\n", count);
 
    return 0;
}
