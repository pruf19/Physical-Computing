#include <stdio.h>
#include <string.h>
 
int main() {
    char text[101];
    char temp[101];
    int i, j;
    int changed;
 
    // รับข้อความ 1 บรรทัด
    scanf(" %[^\n]", text);
 
    do {
        changed = 0;
        j = 0;
 
        // วนลูปตรวจแต่ละตัว
        for (i = 0; text[i] != '\0'; i++) {
            if (text[i] == text[i + 1]) {
                // ถ้ามีตัวติดกันเหมือนกัน → ข้ามทั้งคู่
                i++; 
                changed = 1;
            } else {
                // เก็บตัวที่ไม่ซ้ำติดกันไว้
                temp[j++] = text[i];
            }
        }
        temp[j] = '\0'; // จบสตริง
 
        // ถ้ามีการลบตัวติดกัน
        if (changed) {
            printf("%s\n", temp);
            strcpy(text, temp);
        }
 
    } while (changed); // ทำซ้ำจนไม่มีการเปลี่ยนแปลง
 
    return 0;
}
