#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    char *image = argv[1];
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n ");
        return 1;
    }
    FILE *inptr = fopen(image, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", image);
        return 2;
    }
    unsigned char buffer[512];
    int openfile = 0;
    int jpeg = 0;
    char filename[10];
    FILE *img_file = NULL;
    while (fread(&buffer, 512, 1, inptr))
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (openfile)
            {
                fclose(img_file);
                openfile = 0;
                sprintf(filename, "%03d.jpg", jpeg);
                openfile = 1;
                jpeg ++;
            }
            if (!openfile)
            {
                sprintf(filename, "%03d.jpg", jpeg);
                img_file = fopen(filename, "w");
                openfile = 1;
                jpeg++;
            }
            fwrite(&buffer, 512, 1, img_file);
            return 0;
        }
        else
        {
            if(openfile)
            {
                fwrite(&buffer, 512, 1, img_file);
            }
            if (!openfile)
            {

            }
            return 0;
        }

    }
    fclose(inptr);
    fclose(img_file);
    return 0;

}
