#include <stdio.h>
#include <string.h>
 
typedef struct {
    char name[61];
    char surname[61];
    char sex[10];
    int age;
    char id[13];
    float gpa;
} student_info;
 
int main() {
    student_info student;
 
    // รับข้อมูลนักศึกษา
    scanf("%60s %60s %9s %d %12s %f",
          student.name,
          student.surname,
          student.sex,
          &student.age,
          student.id,
          &student.gpa);
 
    // แสดงคำนำหน้า
    if (strcmp(student.sex, "Male") == 0) {
        printf("Mr ");
    } else if (strcmp(student.sex, "Female") == 0) {
        printf("Miss ");
    }
 
    // แสดงชื่อจริงตัวแรก และนามสกุล
    printf("%c %s (%d) ID: %s GPA %.2f\n",
           student.name[0],
           student.surname,
           student.age,
           student.id,
           student.gpa);
 
    return 0;
}
