#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int pyramidHeight;

    do
    {
        pyramidHeight = get_int("How height is the Pyramid?\n");
    }
    while (pyramidHeight < 1 || pyramidHeight > 8);

    for (int pyramidWidth = 1; pyramidWidth <= pyramidHeight; pyramidWidth++)
    {
        for (int hash = 1; hash <= pyramidHeight; hash++)
        {
            if (hash <= pyramidHeight - pyramidWidth)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
