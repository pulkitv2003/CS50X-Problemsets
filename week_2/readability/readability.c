#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

int count_words(string text);
int count_sentences(string text);
int count_letters(string text);


int main(void)
{
    string text = get_string("Text :");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    float S = (sentences / words) * 100 ;

    float L = (letters / words) * 100 ;
    float calculation = 0.0588 * L - 0.296 * S - 15.8;

    int index = round(calculation);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}
int count_letters(string text)
{
    float letters = 0 ;
    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if ((text[i] >= 97 && text[i] <= 122) || (text[i] >= 65 && text[i] <= 90))
        {
            letters++;
        }

    }
    return letters;

}
int count_words(string text)
{
    int words = 0 ;
    for (int i = 0 ; i <= strlen(text) ; i++)
    {
        if (text[i] == 32 || text[i] == '\0')
        {
            words++;
        }


    }

    return words;

}

int count_sentences(string text)
{
    float sentences = 0;
    for (int i = 0 ; i < strlen(text) ; i ++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }

    }

    return sentences;

}