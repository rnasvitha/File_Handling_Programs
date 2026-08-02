#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp, *temp;
    char line[200];
    char oldWord[50], newWord[50];
    char *ptr;

    fp = fopen("student.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    printf("Enter word to replace: ");
    scanf("%s", oldWord);

    printf("Enter new word: ");
    scanf("%s", newWord);

    while (fgets(line, sizeof(line), fp))
    {
        ptr = strstr(line, oldWord);

        if (ptr != NULL)
        {
            *ptr = '\0';
            fprintf(temp, "%s%s%s", line, newWord, ptr + strlen(oldWord));
        }
        else
        {
            fprintf(temp, "%s", line);
        }
    }

    fclose(fp);
    fclose(temp);

    printf("Replacement completed. Check temp.txt\n");

    return 0;
}
