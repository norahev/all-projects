#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // remember filenames and open the input file
    char *infile = argv[1];
    FILE *inptr = fopen(argv[1], "r");
    // prompt user for correct usage
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;

    }
    //read the raw file
    BYTE buffer[512];
    int jpeg = 0;
    int search = 1; //1 if true, 0 if false
    // pointer to outfile
    FILE *outptr = NULL;
    // go through the cardfile until there aren't any blocks left
    while (fread(buffer, 512, 1, inptr) == true)
    {
        if (search == 1)
        {
            //find the beginning of JPEG
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                char name[8];
                search = 0; //yes, found
                sprintf(name, "%03d.jpg", jpeg);
                outptr = fopen(name, "w");
                fwrite(&buffer, 512, 1, outptr);
            }
            else
            {
                printf("nothing\n"); //not found
            }

        }
        else
        {
            //already found a jpeg?
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
            {
                //yes
                char name[8];
                fclose(outptr);
                jpeg++;
                sprintf(name, "%03d.jpg", jpeg);
                outptr = fopen(name, "w");
                fwrite(&buffer, 512, 1, outptr);
            }
            else
            {
                //no
                fwrite(&buffer, 512, 1, outptr);
            }
        }
    }
// close files
    fclose(inptr);
    fclose(outptr);
    return 0;

}