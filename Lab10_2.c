#include <stdio.h>
#include <string.h>
 
int main() {
    int width;
    char text1[51], text2[41]; // จำกัดความยาวตามสเปก
 
    // รับค่าความกว้างของกล่อง
    scanf("%d", &width);
 
    // รับข้อความ 2 บรรทัด (ใช้ %[^\n] เพื่ออ่านทั้งบรรทัด)
    scanf(" %[^\n]", text1);
    scanf(" %[^\n]", text2);
 
    int inner = width - 2;
    int len1 = strlen(text1);
    int len2 = strlen(text2);
 
    // ตรวจสอบความยาวข้อความ
    if (len1 > inner || len2 > inner) {
        printf("ข้อความยาวเกินขนาดกล่อง\n");
        return 0;
    }
 
    // คำนวณช่องว่างซ้ายขวา
    int left1 = (inner - len1) / 2 + ((inner - len1) % 2);
    int right1 = inner - len1 - left1;
 
    int left2 = (inner - len2) / 2 + ((inner - len2) % 2);
    int right2 = inner - len2 - left2;
 
    // พิมพ์กรอบบน
    for (int i = 0; i < width; i++) printf("*");
    printf("\n");
 
    // แถวข้อความที่ 1
    printf("*");
    for (int i = 0; i < left1; i++) printf(" ");
    printf("%s", text1);
    for (int i = 0; i < right1; i++) printf(" ");
    printf("*\n");
 
    // แถวข้อความที่ 2
    printf("*");
    for (int i = 0; i < left2; i++) printf(" ");
    printf("%s", text2);
    for (int i = 0; i < right2; i++) printf(" ");
    printf("*\n");
 
    // พิมพ์กรอบล่าง
    for (int i = 0; i < width; i++) printf("*");
    printf("\n");
 
    return 0;
}
