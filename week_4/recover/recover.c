#include <stdio.h>
#include <cs50.h>
#include <stdint.h>
#include <stdlib.h>
typedef uint8_t BYTE;


#define buffer_size 512
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./recover card");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 2;
    }
    int flag = 0;
    FILE *tmp = NULL;
    BYTE buffer[512];
    char filename[8];
    int count = 0;

    while (fread(buffer, 512, 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (flag == 1)
            {
                fclose(tmp);
            }
            else
            {
                flag = 1;
            }
            sprintf(filename, "%03i.jpg", count);
            tmp = fopen(filename, "w");
            count++;
        }
        if (flag == 1)
        {
            fwrite(buffer, 512, 1, tmp);
        }

    }
    fclose(tmp);
    fclose(file);



}