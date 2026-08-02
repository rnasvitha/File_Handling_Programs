#include <stdio.h>

void copyContent(FILE *source, FILE *destination)
{
    int ch;

    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }
}

int main()
{
    FILE *student, *employee, *merged;

    student = fopen("student.txt", "r");
    employee = fopen("employee.txt", "r");
    merged = fopen("merged.txt", "w");

    if (student == NULL)
    {
        printf("student.txt not found.\n");
        return 0;
    }

    if (employee == NULL)
    {
        printf("employee.txt not found.\n");
        fclose(student);
        return 0;
    }

    if (merged == NULL)
    {
        printf("Unable to create merged.txt\n");
        fclose(student);
        fclose(employee);
        return 0;
    }

    /* Copy contents of student.txt */
    copyContent(student, merged);

    /* Add a blank line between the two files */
    fputc('\n', merged);

    /* Copy contents of employee.txt */
    copyContent(employee, merged);

    fclose(student);
    fclose(employee);
    fclose(merged);

    printf("student.txt and employee.txt merged successfully into merged.txt.\n");

    return 0;
}
