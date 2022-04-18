#include <stdio.h>
void binary(int n);
int main()
{
    binary(4);
    return 0;
}
void binary(int n)
{
    if (n == 0)
        return;
    else
    {

        binary(n / 2);
        printf("%d", n % 2);
    }
}