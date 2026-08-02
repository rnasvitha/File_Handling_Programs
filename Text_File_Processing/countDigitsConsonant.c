#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    char ch;
    int vowels = 0, consonants = 0, digits = 0, spaces = 0, special = 0;

    fp = fopen("student.txt", "r");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isalpha(ch))
        {
            switch (tolower(ch))
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowels++;
                    break;
                default:
                    consonants++;
            }
        }
        else if (isdigit(ch))
            digits++;
        else if (isspace(ch))
            spaces++;
        else
            special++;
    }

    fclose(fp);

    printf("Vowels      : %d\n", vowels);
    printf("Consonants  : %d\n", consonants);
    printf("Digits      : %d\n", digits);
    printf("Spaces      : %d\n", spaces);
    printf("Special     : %d\n", special);

    return 0;
}
