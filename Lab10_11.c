#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct Student {
    char name[61];
    char surname[61];
    char sex[10];
    char id[13];
    int age;
    double gpa;
};
 
int compare_students(struct Student *a, struct Student *b, const char *data) {
    if (strcmp(data, "name") == 0) {
        return strcmp(a->name, b->name);
    } else if (strcmp(data, "surname") == 0) {
        return strcmp(a->surname, b->surname);
    } else if (strcmp(data, "id") == 0) {
        return strcmp(a->id, b->id);
    }
    return 0;
}
 
int main() {
    struct Student students[20];
    for (int i = 0; i < 20; i++) {
        scanf("%s %s %s %d %s %lf",
              students[i].name,
              students[i].surname,
              students[i].sex,
              &students[i].age,
              students[i].id,
              &students[i].gpa);
    }
 
    char search[10];
    scanf("%s", search);
 
    for (int i = 0; search[i]; i++) {
        search[i] = tolower((unsigned char)search[i]);
    }
    for (int i = 0; i < 19; i++) {
        int min_d = i;
        for (int j = i + 1; j < 20; j++) {
            if (compare_students(&students[j], &students[min_d], search) < 0) {
                min_d = j;
            }
        }
        if (min_d != i) {
            struct Student tempStudent = students[i];
            students[i] = students[min_d];
            students[min_d] = tempStudent;
        }
    }
    for (int i = 0; i < 20; i++) {
        char title[10];
        if (strcmp(students[i].sex, "Male") == 0) {
            strcpy(title, "Mr");
        } else {
            strcpy(title, "Miss");
        }
 
        printf("%s %c %s (%d) ID: %s GPA %.2lf\n",
               title,
               students[i].name[0],
               students[i].surname,
               students[i].age,
               students[i].id,
               students[i].gpa);
    }
 
    return 0;
}
