#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize;

    do
    {
        startSize = get_int("Start Size: ");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    int endSize;

    do
    {
        endSize = get_int("End Size: ");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    int years, bornLlamas, diedLlamas;
    years = 0;

    while (startSize < endSize)
    {
        bornLlamas = startSize / 3;
        diedLlamas = startSize / 4;
        startSize = startSize + bornLlamas - diedLlamas;
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}

