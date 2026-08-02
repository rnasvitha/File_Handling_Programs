#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    int n, i, roll;
    char name[50];
    float marks;

    fp = fopen("students.csv", "w");

    if (fp == NULL)
    {
        printf("Cannot create file.\n");
        return 0;
    }

    fprintf(fp, "Roll,Name,Marks\n");

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Roll: ");
        scanf("%d", &roll);

        printf("Name: ");
        scanf(" %[^\n]", name);

        printf("Marks: ");
        scanf("%f", &marks);

        fprintf(fp, "%d,%s,%.2f\n", roll, name, marks);
    }

    fclose(fp);

    fp = fopen("students.csv", "r");

    char line[100];
    float total = 0;
    int count = 0;

    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp))
    {
        char *token;

        token = strtok(line, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");

        total += atof(token);
        count++;
    }

    fclose(fp);

    printf("\nAverage Marks = %.2f\n", total / count);

    return 0;
}
