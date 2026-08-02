#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    FILE *fp, *temp;
    struct Employee emp;
    int deleteId, found = 0;

    fp = fopen("employee.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("File error.\n");
        return 0;
    }

    printf("Enter Employee ID to delete: ");
    scanf("%d", &deleteId);

    while (fread(&emp, sizeof(struct Employee), 1, fp))
    {
        if (emp.id != deleteId)
        {
            fwrite(&emp, sizeof(struct Employee), 1, temp);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("employee.dat");
    rename("temp.dat", "employee.dat");

    if (found)
        printf("Record deleted successfully.\n");
    else
        printf("Employee ID not found.\n");

    return 0;
}
