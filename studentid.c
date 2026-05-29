#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[30];
    int age;
};

void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.dat", "ab");
    printf("ID: "); scanf("%d", &s.id);
    printf("Name: "); scanf("%s", s.name);
    printf("Age: "); scanf("%d", &s.age);
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}

void displayStudents() {
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    if (!fp) { printf("No records!\n"); return; }
    while (fread(&s, sizeof(s), 1, fp))
        printf("%d %s %d\n", s.id, s.name, s.age);
    fclose(fp);
}

void searchStudent() {
    int id, found=0; struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    printf("Enter ID: "); scanf("%d", &id);
    while (fread(&s, sizeof(s), 1, fp))
        if (s.id==id) { printf("%d %s %d\n", s.id,s.name,s.age); found=1; }
    if(!found) printf("Not found!\n");
    fclose(fp);
}

void updateStudent() {
    int id; struct Student s;
    FILE *fp = fopen("students.dat", "rb+");
    printf("Enter ID to update: "); scanf("%d", &id);
    while (fread(&s, sizeof(s), 1, fp))
        if (s.id==id) {
            printf("New Name: "); scanf("%s", s.name);
            printf("New Age: "); scanf("%d", &s.age);
           fseek(fp, -(long)sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            break;
        }
    fclose(fp);
}

void deleteStudent() {
    int id; struct Student s;
    FILE *fp=fopen("students.dat","rb"), *temp=fopen("temp.dat","wb");
    printf("Enter ID to delete: "); scanf("%d",&id);
    while(fread(&s,sizeof(s),1,fp))
        if(s.id!=id) fwrite(&s,sizeof(s),1,temp);
    fclose(fp); fclose(temp);
    remove("students.dat"); rename("temp.dat","students.dat");
}

int main() {
    int ch;
    do {
        printf("\n1.Add 2.Display 3.Search 4.Update 5.Delete 6.Exit\nChoice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:addStudent();break;
            case 2:displayStudents();break;
            case 3:searchStudent();break;
            case 4:updateStudent();break;
            case 5:deleteStudent();break;
        }
    } while(ch!=6);
    return 0;
}
