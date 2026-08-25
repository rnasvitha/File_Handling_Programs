#include <stdio.h>

int main(void)
{
    FILE *file;

    int id;
    int quantity;
    char name[100];
    float price;

    file = fopen("product.json", "r");

    if (file == NULL)
    {
        printf("Unable to open product.json\n");
        return 1;
    }

    /*
     * This works only when product.json follows the exact
     * predefined format shown above.
     */
    if (fscanf(file,
               " {\n \"id\": %d,\n \"name\": \"%99[^\"]\",\n"
               " \"price\": %f,\n \"quantity\": %d\n }",
               &id, name, &price, &quantity) != 4)
    {
        printf("Invalid or unexpected JSON format.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Product ID   : %d\n", id);
    printf("Product Name : %s\n", name);
    printf("Price        : %.2f\n", price);
    printf("Quantity     : %d\n", quantity);

    return 0;
}
