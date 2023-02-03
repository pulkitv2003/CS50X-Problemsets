#include<stdio.h>
#include<cs50.h>

int checksum(long Number);
void credit_name(long Number);
int main(void)
{
    long credit_number = get_long("Number : ");
    int sum3 = checksum(credit_number);
    if ((sum3 % 10) == 0)
    {
        credit_name(credit_number);
    }
    else
    {
        printf("INVALID\n");
    }

}
int checksum(long x)
{
    int odd, even, sum1 = 0, sum2 = 0, sum3 ;
    while (x > 0)
    {

        odd = x % 10;
        sum1 = sum1 + odd;
        x = x / 10;
        even = x % 10;
        x = x / 10;
        even = even * 2;
        if (even / 10 == 1)
        {
            sum2 = sum2 + (even % 10) + (even / 10) ;
        }
        else if (even / 10 != 1)
        {
            sum2 = sum2 + even;
        }

    }
    sum3 = sum1 + sum2;
    return sum3;

}
void credit_name(long x)
{

    if ((x > 340000000000000 && x < 349999999999999) || (x > 370000000000000 && x < 3799999999999999))
    {
        printf("AMEX\n");
    }
    else if ((x > 4000000000000 && x < 4999999999999) || (x > 4000000000000000 && x < 4999999999999999))
    {
        printf("VISA\n");
    }
    else if (x > 5100000000000000 && x < 5599999999999999)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}