#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover <filename>\n");
        return 1;
    }

    FILE *file_pointer = fopen(argv[1], "r");
    if (!file_pointer)
    {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    FILE *output_file_pointer = NULL;

    BYTE buffer[512];

    int total_images = 0;

    char file_name[30];

    while (fread(buffer, sizeof(BYTE) * 512, 1, file_pointer) == 1)
    {

        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
        {

            if (output_file_pointer != NULL)
            {
                fclose(output_file_pointer);
            }

            sprintf(file_name, "%03d.jpg", total_images++);

            output_file_pointer = fopen(file_name, "w");
        }
        if (output_file_pointer != NULL)
        {
            fwrite(buffer, sizeof(BYTE) * 512, 1, output_file_pointer);
        }
    }

    if (output_file_pointer != NULL)
    {
        fclose(output_file_pointer);
    }

    fclose(file_pointer);

    return 0;
}
