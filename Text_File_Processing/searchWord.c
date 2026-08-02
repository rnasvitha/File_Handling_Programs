#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char line[200], word[50];
    int count = 0;
    char *ptr;

    fp = fopen("student.txt", "r");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return 0;
    }

    printf("Enter word to search: ");
    scanf("%s", word);

    while (fgets(line, sizeof(line), fp))
    {
        ptr = line;

        while ((ptr = strstr(ptr, word)) != NULL)
        {
            count++;
            ptr += strlen(word);
        }
    }

    fclose(fp);

    printf("'%s' found %d time(s).\n", word, count);

    return 0;
}
