#include <stdio.h>

void writeStudent()
{
    FILE *fp;
    char name[50];
    int roll;
    float marks;

    fp = fopen("student.txt", "w");

    if (fp == NULL)
    {
        printf("File cannot be created.\n");
        return;
    }

    printf("Enter Name: ");
    fgets(name,sizeof(name),stdin);

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    printf("Enter Marks: ");
    scanf("%f", &marks);

    fprintf(fp, "Name : %s\n", name);
    fprintf(fp, "Roll Number : %d\n", roll);
    fprintf(fp, "Marks : %.2f\n", marks);

    fclose(fp);

    printf("Student details written successfully.\n");
}

int main()
{
    writeStudent();
    return 0;
}
