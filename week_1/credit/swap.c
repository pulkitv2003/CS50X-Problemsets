#include<stdio.h>

void fun(int x , int y);
int main(void)
{
    int x = 10;
    int y = 20;
    swap(x,y);
    printf("x :%d\n",x);
    printf("y : %d\n",y);
}
void fun(int x , int y)
{
    x = 20;
    y = 10;
}