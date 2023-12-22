#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    int letters = 0;
    int words = 0;
    int sentences = 0;

    string text = get_string("Text: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }

        words = text[i] == ' ' ? words + 1 : words;

        sentences = (text[i] == '.' || text[i] == '!' || text[i] == '?') ? sentences + 1 : sentences;
    }
    words++;

    float L = (float) letters * 100 / (float) words;
    float S = (float) sentences * 100 / (float) words;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
        ;
    }
}
