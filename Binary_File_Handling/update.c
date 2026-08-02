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
    struct Employee emp;
    int searchId, found = 0;

    fp = fopen("employee.dat", "rb+");

    if (fp == NULL)
    {
        printf("employee.dat not found.\n");
        return 0;
    }

    printf("Enter Employee ID to update: ");
    scanf("%d", &searchId);

    while (fread(&emp, sizeof(struct Employee), 1, fp))
    {
        if (emp.id == searchId)
        {
            printf("Current Salary: %.2f\n", emp.salary);

            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);

            fseek(fp, -sizeof(struct Employee), SEEK_CUR);

            fwrite(&emp, sizeof(struct Employee), 1, fp);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found)
        printf("Salary updated successfully.\n");
    else
        printf("Employee not found.\n");

    return 0;
}
