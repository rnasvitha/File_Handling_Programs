#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char line[200];
    int lines = 0, words = 0, characters = 0, i;

    fp = fopen("student.txt", "r");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return 0;
    }

    while (fgets(line, sizeof(line), fp))
    {
        lines++;
        characters += strlen(line);

        for (i = 0; line[i] != '\0'; i++)
        {
            if ((i == 0 && line[i] != ' ' && line[i] != '\n') ||
                (line[i] != ' ' && line[i - 1] == ' '))
            {
                words++;
            }
        }
    }

    fclose(fp);

    printf("Lines      : %d\n", lines);
    printf("Words      : %d\n", words);
    printf("Characters : %d\n", characters);

    return 0;
}
