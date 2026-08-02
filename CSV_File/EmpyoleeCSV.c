#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    FILE *fp;
    char line[100];
    struct Employee emp;

    fp = fopen("employee.csv", "r");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return 0;
    }

    fgets(line, sizeof(line), fp);

    printf("Employees with Salary > 50000\n\n");

    while (fgets(line, sizeof(line), fp))
    {
        char *token;

        token = strtok(line, ",");
        emp.id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(emp.name, token);

        token = strtok(NULL, ",");
        emp.salary = atof(token);

        if (emp.salary > 50000)
        {
            printf("%d\t%s\t%.2f\n",
                   emp.id,
                   emp.name,
                   emp.salary);
        }
    }

    fclose(fp);

    return 0;
}
