#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
#define BLOCKSIZE 512

int main(int argc, char *argv[])
{
    // Check if CLA valid
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open memory card pointer
    FILE *card = fopen(argv[1], "r");

    // Check if valid point is returned
    if (card == NULL)
    {
        printf("Failed to open file.");
        return 1;
    }

    // Creating buffer
    BYTE buffer[BLOCKSIZE];

    // file pointer for found jpgs
    FILE *found_image_ptr = NULL;

    // image name. 000.jpg (1 byte each char + /0)
    char *image_name = malloc(8);

    // Image counter
    int count = 0;

    // is there a JPEG header in this block?
    while (fread(&buffer, BLOCKSIZE, 1, card) > 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            // removing close from first iteration as it is not yet open
            if (count != 0)
            {
                fclose(found_image_ptr);
            }
            count++;
            // prints string directly to image name string with this format
            sprintf(image_name, "%03i.jpg", count);
            // open image_name pointer in writing mode - dereference
            found_image_ptr = fopen(image_name, "w");
        }
        // if image found
        if (count != 0)
        {
            fwrite(&buffer, BLOCKSIZE, 1, found_image_ptr);
        }
    }
    fclose(card);
    fclose(found_image_ptr);
    free(image_name);
    return 0;
}