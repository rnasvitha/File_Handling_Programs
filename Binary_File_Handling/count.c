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
    long size;
    int records;

    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END);

    size = ftell(fp);

    records = size / sizeof(struct Employee);

    printf("Total Employee Records = %d\n", records);

    fclose(fp);

    return 0;
}
