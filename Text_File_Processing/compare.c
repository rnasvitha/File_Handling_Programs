#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    char ch1, ch2;

    fp1 = fopen("student.txt", "r");
    fp2 = fopen("merged.txt", "r");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Error opening files.\n");
        return 0;
    }

    do
    {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);

        if (ch1 != ch2)
        {
            printf("Files are different.\n");
            fclose(fp1);
            fclose(fp2);
            return 0;
        }

    } while (ch1 != EOF && ch2 != EOF);

    printf("Files are identical.\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}
