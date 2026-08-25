#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *csvFile;
    FILE *jsonFile;

    char line[300];
    int id;
    char name[100];
    char department[100];
    float salary;

    int firstRecord = 1;

    csvFile = fopen("employees.csv", "r");
    jsonFile = fopen("employees.json", "w");

    if (csvFile == NULL || jsonFile == NULL)
    {
        printf("Unable to open input or output file.\n");

        if (csvFile != NULL)
            fclose(csvFile);

        if (jsonFile != NULL)
            fclose(jsonFile);

        return 1;
    }

    /* Skip CSV header */
    fgets(line, sizeof(line), csvFile);

    fprintf(jsonFile, "[\n");

    while (fgets(line, sizeof(line), csvFile) != NULL)
    {
        if (sscanf(line, "%d,%99[^,],%99[^,],%f",
                   &id, name, department, &salary) == 4)
        {
            if (!firstRecord)
                fprintf(jsonFile, ",\n");

            fprintf(jsonFile, "    {\n");
            fprintf(jsonFile, "        \"id\": %d,\n", id);
            fprintf(jsonFile, "        \"name\": \"%s\",\n", name);
            fprintf(jsonFile,
                    "        \"department\": \"%s\",\n",
                    department);
            fprintf(jsonFile, "        \"salary\": %.2f\n", salary);
            fprintf(jsonFile, "    }");

            firstRecord = 0;
        }
    }

    fprintf(jsonFile, "\n]\n");

    fclose(csvFile);
    fclose(jsonFile);

    printf("CSV converted to employees.json\n");

    return 0;
}
