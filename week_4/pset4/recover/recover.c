#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // make sure the user entered a card name as the second argument
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // open file to read the card entered
    FILE *file = fopen(argv[1], "r");

    // file pointer to write into the images
    FILE *img = NULL;

    // array of 8 chars to save the name of the current image
    char filename[8];

    // current image number
    int found = 0;

    // array to store the 512 byte form the memory

    BYTE arr[512];
    while (fread(arr, 512, 1, file) == 1)
    {
        if (arr[0] == 0xff && arr[1] == 0xd8 && arr[2] == 0xff && (arr[3] & 0xf0) == 0xe0)
        {
            // if it is the first jpeg image then no need to close the previous file
            if (found == 0)
            {
                // start writting then
                img = fopen("000.jpg", "w");
                fwrite(arr, sizeof(BYTE), 512, img);
                found ++;
            }
            else
            {
                // close the previous one and start writting
                fclose(img);
                sprintf(filename, "%03i.jpg", found);
                img = fopen(filename, "w");
                fwrite(arr, sizeof(BYTE), 512, img);
                found++;
            }
        }
        else
        {
            // if found > 0 then the cuurent 512byte is the rest of the previous one
            // so continue writting, else do nothing and continue looping till finding
            //  jpeg file
            if (found > 0)
            {
                fwrite(arr, sizeof(BYTE), 512, img);
            }
        }
    }
    fclose(img);
    fclose(file);
}
