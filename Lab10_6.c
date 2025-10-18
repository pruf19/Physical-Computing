#include <stdio.h>
#include <string.h>
 
int main() {
    char text[201];
    int i, j;
    char temp;
 
    // รับข้อความ 1 บรรทัด (ยาวไม่เกิน 200 ตัวอักษร)
    scanf(" %[^\n]", text);
 
    int len = strlen(text);
 
    // เรียงลำดับตัวอักษรตามค่า ASCII (Bubble Sort)
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (text[j] > text[j + 1]) {
                temp = text[j];
                text[j] = text[j + 1];
                text[j + 1] = temp;
            }
        }
    }
 
    // แสดงผลข้อความที่เรียงแล้ว
    printf("%s\n", text);
 
    return 0;
}
