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
    int n, i;

    fp = fopen("employee.dat", "wb");

    if(fp == NULL)
    {
        printf("Cannot create file.\n");
        return 0;
    }

    printf("Enter number of employees: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEmployee %d\n",i+1);

        printf("Enter ID: ");
        scanf("%d",&emp.id);

        printf("Enter Name: ");
        scanf(" %[^\n]",emp.name);

        printf("Enter Salary: ");
        scanf("%f",&emp.salary);

        fwrite(&emp,sizeof(struct Employee),1,fp);
    }

    fclose(fp);

    printf("\nemployee.dat created successfully.\n");

    return 0;
}
