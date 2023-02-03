#include <stdio.h>
#include <cs50.h>
#include <stdint.h>
#include <stdlib.h>
typedef uint8_t BYTE;


#define buffer_size 512
int main(int argc, char *argv[])
{

    FILE* file = fopen(argv[1], "r");
    bool flag = false;
    FILE* tmp=NULL;
    BYTE buffer[buffer_size];
    char filename[10];
    int count = 0;

    while(fread(&buffer,buffer_size,1,file)==1)
    {
        if(flag == false)
        {
            if(buffer[0] == 0xff || buffer[1] == 0xd8 || buffer[2] == 0xff || (buffer[3] & 0xf0) == 0xe0)
            {
                sprintf(filename,"%03i.jpg",count);
                tmp = fopen(filename,"w");
                flag = true;
            }
        }
        if(flag == true)
        {
            if(count > 0)
            {
                fclose(tmp);
            }
            fwrite(buffer,buffer_size,1,tmp);
        }
    }



}