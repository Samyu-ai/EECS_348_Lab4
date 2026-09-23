/*
 * Name: Samyu Aitha
 * Lab: Lab 4 - C Programming
 * Student ID: 3222133
 * Input: Temp value in either C, F, or K
 * Output: Convertions of temp between the degrees
 * Description: Converts temperatures between Celsius, Fahrenheit, and Kelvin, then displays a temperature category and weather advisory.
 */

#include <stdio.h>
#include <ctype.h>

/* Convert any supported temperature to Celsius */
double toCelsius(double temperature, char scale)
{
    if (scale == 'F')
    {
        return (temperature - 32.0) * 5.0 / 9.0;
    }
    else if (scale == 'K')
    {
        return temperature - 273.15;
    }

    return temperature;
}

/* Convert Celsius to the requested scale */
double fromCelsius(double celsius, char scale)
{
    if (scale == 'F')
    {
        return (celsius * 9.0 / 5.0) + 32.0;
    }
    else if (scale == 'K')
    {
        return celsius + 273.15;
    }

    return celsius;
}

void displayCategory(double celsius)
{
    if (celsius < 0)
    {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Bundle up and stay warm!\n");
    }
    else if (celsius < 10)
    {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    }
    else if (celsius < 25)
    {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Enjoy the weather!\n");
    }
    else if (celsius < 35)
    {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    }
    else
    {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors and keep hydrated!\n");
    }
}

int validScale(char scale)
{
    return scale == 'C' || scale == 'F' || scale == 'K';
}

int main(void)
{
    double temperature;
    double celsius;
    double converted;

    char originalScale;
    char targetScale;
    char extra;

    printf("Enter the temperature value: ");

    if (scanf("%lf", &temperature) != 1)
    {
        printf("Invalid temperature value.\n");
        return 1;
    }

    /* Remove rest of current line */
    while ((extra = getchar()) != '\n' && extra != EOF)
    {
    }

    printf("Enter the original scale (C, F, or K): ");

    if (scanf(" %c", &originalScale) != 1)
    {
        printf("Invalid scale.\n");
        return 1;
    }

    originalScale = toupper(originalScale);

    if (!validScale(originalScale))
    {
        printf("Invalid scale. Please enter C, F, or K.\n");
        return 1;
    }

    printf("Enter the scale to convert to (C, F, or K): ");

    if (scanf(" %c", &targetScale) != 1)
    {
        printf("Invalid scale.\n");
        return 1;
    }

    targetScale = toupper(targetScale);

    if (!validScale(targetScale))
    {
        printf("Invalid scale. Please enter C, F, or K.\n");
        return 1;
    }

    /*
     * Convert original temperature to Celsius first.
     * Celsius is then used as the common intermediate value.
     */
    celsius = toCelsius(temperature, originalScale);

    /*
     * Reject temperatures below absolute zero.
     */
    if (celsius < -273.15)
    {
        printf("Invalid temperature. Temperature cannot be below absolute zero.\n");
        return 1;
    }

    converted = fromCelsius(celsius, targetScale);

    printf("Converted temperature: %.2f %c\n",
           converted,
           targetScale);

    displayCategory(celsius);

    return 0;
}
