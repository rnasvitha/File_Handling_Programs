#include <stdio.h>

int main()
{
    FILE *fp;
    int id;
    char name[50];
    float salary;

    fp = fopen("employee.txt", "a");

    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return 0;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    printf("Enter Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Salary: ");
    scanf("%f", &salary);

    fprintf(fp, "%d %s %.2f\n", id, name, salary);

    fclose(fp);

    printf("Record appended successfully.\n");

    return 0;
}
