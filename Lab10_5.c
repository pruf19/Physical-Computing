#include <stdio.h>
 
int main() {
    char first[101], last[101];
 
    // รับชื่อและนามสกุล (1 บรรทัด)
    scanf("%s %s", first, last);
 
    // แสดงชื่อย่อ
    printf("%c.%c.\n", first[0], last[0]);
 
    return 0;
}
