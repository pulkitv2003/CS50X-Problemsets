#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;

    }
    string s = get_string("plaintext:  ");
    int key = atoi(argv[1]);
    printf("ciphertext: ");
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            printf("%c", ((s[i] + key - 97) % 26) + 97);
        }
        else if (s[i] >= 65 && s[i] <= 90)
        {
            printf("%c", ((s[i] + key - 65) % 26) + 65);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
bool only_digits(string s)
{
    for (int i = 0 ; i < strlen(s) ; i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return false;
        }
    }
    return true;

}