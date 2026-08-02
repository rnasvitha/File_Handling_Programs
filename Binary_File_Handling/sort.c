#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    FILE *fp;
    struct Employee emp[100], temp;
    int n = 0, i, j;

    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return 0;
    }

    while (fread(&emp[n], sizeof(struct Employee), 1, fp))
    {
        n++;
    }

    fclose(fp);

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (emp[j].id > emp[j + 1].id)
            {
                temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }

    fp = fopen("employee.dat", "wb");

    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        fwrite(&emp[i], sizeof(struct Employee), 1, fp);
    }

    fclose(fp);

    printf("Records sorted successfully.\n\n");

    printf("Sorted Employee Records\n");
    printf("-----------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("ID     : %d\n", emp[i].id);
        printf("Name   : %s\n", emp[i].name);
        printf("Salary : %.2f\n\n", emp[i].salary);
    }

    return 0;
}
