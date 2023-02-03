#include<stdio.h>
#include<cs50.h>

int main(void)
{
// enter your name 
    string name = get_string("your name: ");
    printf("hello %s\n", name);
}