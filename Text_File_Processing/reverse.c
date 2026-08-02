#include <stdio.h>

int main()
{
    FILE *source, *destination;
    long size;
    char ch;

    source = fopen("student.txt", "r");
    destination = fopen("reverse.txt", "w");

    if (source == NULL || destination == NULL)
    {
        printf("File error.\n");
        return 0;
    }

    fseek(source, 0, SEEK_END);

    size = ftell(source);

    while (size--)
    {
        fseek(source, size, SEEK_SET);
        ch = fgetc(source);
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("Reverse file created successfully.\n");

    return 0;
}
