#include <stdio.h>
#include <time.h>

int main(void)
{
    FILE *file;
    int deviceId;
    float temperature, humidity, pressure;
    time_t currentTime;

    printf("Enter device ID: ");
    scanf("%d", &deviceId);

    printf("Enter temperature: ");
    scanf("%f", &temperature);

    printf("Enter humidity: ");
    scanf("%f", &humidity);

    printf("Enter pressure: ");
    scanf("%f", &pressure);

    currentTime = time(NULL);

    file = fopen("sensor_data.json", "w");

    if (file == NULL)
    {
        printf("Unable to create JSON file.\n");
        return 1;
    }

    fprintf(file, "{\n");
    fprintf(file, "    \"device_id\": %d,\n", deviceId);
    fprintf(file, "    \"temperature\": %.2f,\n", temperature);
    fprintf(file, "    \"humidity\": %.2f,\n", humidity);
    fprintf(file, "    \"pressure\": %.2f,\n", pressure);
    fprintf(file, "    \"timestamp\": %ld\n", (long)currentTime);
    fprintf(file, "}\n");

    fclose(file);

    printf("Sensor data written to sensor_data.json\n");

    return 0;
}
