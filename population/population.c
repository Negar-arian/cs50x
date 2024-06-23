#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int st;
    do
    {
        st = get_int("Start size: ");
    }
    while (st < 9);
    int ed;
    do
    {
        ed = get_int("End size: ");
    }
    while (ed < st);
    int years = 0;
    while (st < ed)
    {
        st = st + (st / 3) - (st / 4);
        years++;
    }
    printf("Years: %i\n", years);
}
